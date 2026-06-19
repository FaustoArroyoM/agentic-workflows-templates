// EXAMPLE C++ node (ament_cmake).
//
// Same behaviour as the Python example: PUBLISH + SUBSCRIBE + TIMER. It
// publishes and subscribes to the same topic so you can see it hear itself.
//
// ========================================================================
// HOW TO MAKE YOUR OWN C++ NODE FROM THIS:
//   1. Copy this file:  src/my_node.cpp
//   2. Rename the class and the string in Node("...").
//   3. Change the topic names + message types to the ones in Claude.md.
//   4. In CMakeLists.txt add:
//        add_executable(my_node src/my_node.cpp)
//        ament_target_dependencies(my_node rclcpp std_msgs)
//        install(TARGETS my_node DESTINATION lib/${PROJECT_NAME})
//   5. From robot_ws/:  ./build.sh  &&  source install/setup.bash
//   6. Run it:          ros2 run example_cpp_pkg my_node
// ========================================================================

#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class ExampleNode : public rclcpp::Node
{
public:
  ExampleNode() : Node("example_node"), count_(0)
  {
    // PUBLISHER: <message type>("topic name", queue size)
    pub_ = create_publisher<std_msgs::msg::String>("/example_chatter", 10);

    // SUBSCRIBER: ("topic name", queue size, callback)
    sub_ = create_subscription<std_msgs::msg::String>(
      "/example_chatter", 10,
      std::bind(&ExampleNode::on_msg, this, std::placeholders::_1));

    // TIMER: run tick() every 500 ms
    timer_ = create_wall_timer(500ms, std::bind(&ExampleNode::tick, this));

    RCLCPP_INFO(get_logger(), "example_node started ✓");
  }

private:
  void tick()
  {
    // Periodic work: build a message and publish it.
    std_msgs::msg::String msg;
    msg.data = "hello " + std::to_string(count_++);
    pub_->publish(msg);
  }

  void on_msg(const std_msgs::msg::String & msg) const
  {
    // Runs on every incoming message. Keep it fast: no sleeps/blocking here.
    RCLCPP_INFO(get_logger(), "heard: %s", msg.data.c_str());
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
  rclcpp::TimerBase::SharedPtr timer_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ExampleNode>());
  rclcpp::shutdown();
  return 0;
}
