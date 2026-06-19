cmake_minimum_required(VERSION 3.8)
project(example_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. find every package we depend on (must match <depend> in package.xml)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# 2. compile one executable from one (or more) source files.
#    To add another node: another add_executable + ament_target_dependencies pair.
add_executable(example_node src/example_node.cpp)
ament_target_dependencies(example_node rclcpp std_msgs)

# 3. install the built binary so `ros2 run example_cpp_pkg example_node` finds it
install(TARGETS example_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
