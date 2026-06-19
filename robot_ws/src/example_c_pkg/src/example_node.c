// EXAMPLE C node (ament_cmake, rclc).
//
// Same behaviour as the Python/C++ examples: PUBLISH + SUBSCRIBE + TIMER.
// Uses rclc -- the official C client library for ROS2, same library that
// micro-ROS uses on microcontrollers, but here compiled for Linux on the Pi.
//
// ========================================================================
// HOW TO MAKE YOUR OWN C NODE FROM THIS:
//   1. Copy this file:  src/my_node.c
//   2. Change the string in rclc_node_init_default() to your node name.
//   3. Change the topic names + message types to the ones in docs/ARCHITECTURE.md.
//      (search ROSIDL_GET_MSG_TYPE_SUPPORT for how to swap message types)
//   4. In CMakeLists.txt add:
//        add_executable(my_node src/my_node.c)
//        ament_target_dependencies(my_node rcl rclc std_msgs)
//        install(TARGETS my_node DESTINATION lib/${PROJECT_NAME})
//   5. From robot_ws/:  ./build.sh  &&  source install/setup.bash
//   6. Run it:          ros2 run example_c_pkg my_node
// ========================================================================

#include <stdio.h>
#include <string.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/string.h>
#include <rosidl_runtime_c/string_functions.h>

// rclc callbacks are plain C functions, not methods, so state lives here.
static rcl_publisher_t  g_pub;
static std_msgs__msg__String g_pub_msg;
static std_msgs__msg__String g_sub_msg;
static int g_count = 0;

// ── callbacks ──────────────────────────────────────────────────────────────
// IMPORTANT: keep callbacks fast -- no sleep(), no blocking I/O here.

void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
  (void)last_call_time;
  if (!timer) return;

  char buf[64];
  snprintf(buf, sizeof(buf), "hello %d", g_count++);

  // assign copies the string and manages the heap buffer for you
  rosidl_runtime_c__String__assign(&g_pub_msg.data, buf);
  rcl_publish(&g_pub, &g_pub_msg, NULL);
}

void subscription_callback(const void * msgin)
{
  const std_msgs__msg__String * msg = (const std_msgs__msg__String *)msgin;
  printf("[example_c_node] heard: %s\n", msg->data.data);
}

// ── main ───────────────────────────────────────────────────────────────────

int main(int argc, char * argv[])
{
  rcl_allocator_t   allocator  = rcl_get_default_allocator();
  rclc_support_t    support;
  rcl_node_t        node;
  rcl_subscription_t subscriber;
  rcl_timer_t       timer;
  rclc_executor_t   executor;

  rclc_support_init(&support, argc, argv, &allocator);

  // Node
  rclc_node_init_default(&node, "example_c_node", "", &support);

  // Publisher: (node, type_support, topic_name)
  rclc_publisher_init_default(
    &g_pub, &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),
    "/example_chatter");

  // Subscriber
  rclc_subscription_init_default(
    &subscriber, &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),
    "/example_chatter");

  // Timer: fires every 500 ms
  rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(500), timer_callback);

  // Init message memory BEFORE handing to the executor
  std_msgs__msg__String__init(&g_pub_msg);
  std_msgs__msg__String__init(&g_sub_msg);

  // Executor: 2 handles = 1 subscriber + 1 timer
  rclc_executor_init(&executor, &support.context, 2, &allocator);
  rclc_executor_add_subscription(
    &executor, &subscriber, &g_sub_msg, &subscription_callback, ON_NEW_DATA);
  rclc_executor_add_timer(&executor, &timer);

  printf("[example_c_node] started ✓\n");
  rclc_executor_spin(&executor);    // blocks until Ctrl-C

  // Cleanup
  std_msgs__msg__String__fini(&g_pub_msg);
  std_msgs__msg__String__fini(&g_sub_msg);
  rcl_publisher_fini(&g_pub, &node);
  rcl_subscription_fini(&subscriber, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor);
  rcl_node_fini(&node);
  rclc_support_fini(&support);

  return 0;
}
