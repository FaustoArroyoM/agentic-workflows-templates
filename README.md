# TUM Science Hackathon

## Repo map

| Path | What it is |
|---|---|
| [robot_ws/](robot_ws/) | The ROS2 (Humble) workspace — all robot code lives here. |
| [robot_ws/README.md](robot_ws/README.md) | Install, build, and run the system. |
| [robot_ws/DEVELOPING.md](robot_ws/DEVELOPING.md) | How to write your own nodes + manage dependencies — **start here if you're new to ROS2.** |

## Quick start

```bash
cd robot_ws
# full install steps are in robot_ws/README.md; once ROS2 is set up:
./build.sh && source install/setup.bash
ros2 launch robot_bringup bringup.launch.py
```

