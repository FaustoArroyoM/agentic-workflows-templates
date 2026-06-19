cmake_minimum_required(VERSION 3.8)
project(example_c_pkg)

# rclc is the C client library (same one micro-ROS uses on MCUs).
# CMake handles C and C++ natively; build type is still ament_cmake.
find_package(ament_cmake REQUIRED)
find_package(rcl         REQUIRED)
find_package(rclc        REQUIRED)
find_package(std_msgs    REQUIRED)

add_executable(example_node src/example_node.c)
ament_target_dependencies(example_node rcl rclc std_msgs)
install(TARGETS example_node DESTINATION lib/${PROJECT_NAME})

# ── To add your own node: ────────────────────────────────────────────────
# add_executable(my_node src/my_node.c)
# ament_target_dependencies(my_node rcl rclc std_msgs)   # add more packages as needed
# install(TARGETS my_node DESTINATION lib/${PROJECT_NAME})

ament_package()
