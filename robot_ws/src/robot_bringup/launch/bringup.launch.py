"""
Whole-robot bringup. Start everything with one command:

    ros2 launch robot_bringup bringup.launch.py

A launch file is just a Python function that returns a list of nodes to start.
Right now it launches the two EXAMPLE nodes so you can watch the system come up.
As you build real nodes:
  - add a Node(...) line for each one (package + executable + a name),
  - delete the example lines,
  - uncomment the external drivers once that hardware/package is installed.

`executable` must match what you registered:
  Python -> the name in that package's setup.py console_scripts
  C++    -> the add_executable() target in that package's CMakeLists.txt
"""
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        # ── EXAMPLES (delete once you have real nodes) ───────────────────
        Node(package='example_py_pkg',  executable='example_node', name='py_example'),
        Node(package='example_cpp_pkg', executable='example_node', name='cpp_example'),

        # ── YOUR NODES go here — one Node(...) per executable, e.g.:
        # Node(package='perception', executable='yolo_detector',    name='yolo'),
        # Node(package='navigation', executable='obstacle_avoider', name='nav'),
        # Node(package='control',    executable='motor_controller', name='motors'),

        # ── EXTERNAL / off-the-shelf drivers (install, then uncomment):
        # Node(package='usb_cam',      executable='usb_cam_node_exe',        name='camera'),
        # Node(package='sllidar_ros2', executable='sllidar_node',           name='lidar'),
        # Node(package='slam_toolbox', executable='async_slam_toolbox_node', name='slam'),
    ])
