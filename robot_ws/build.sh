#!/usr/bin/env bash
# One-command build for the robot workspace.
# Run from anywhere; it builds robot_ws/ and reminds you to source the result.
set -e
cd "$(dirname "$0")"

if ! command -v colcon >/dev/null 2>&1; then
  echo "colcon not found. Did you 'source /opt/ros/\$ROS_DISTRO/setup.bash' first?"
  exit 1
fi

colcon build --symlink-install

echo
echo "Build OK. In each terminal you use, run:"
echo "    source $(pwd)/install/setup.bash"
echo "Then try: ros2 run example_py_pkg example_node"
