# TUM Science Hackathon

## Repo map

| Path | What it is |
|---|---|
| [AGENTS.md](AGENTS.md) | **Start here** — how we work together + where each doc lives. (Claude Code loads it via `.claude/CLAUDE.md`, which imports it.) |
| [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) | What we're building + how the pieces fit — the shared design. |
| [docs/DECISIONS.md](docs/DECISIONS.md) | Append-only log of decisions & changes — the *why*. |
| [docs/HOW_TO_ROS2.md](docs/HOW_TO_ROS2.md) | Working with the ROS2 starter templates — **start here if you're new to ROS2.** |
| [robot_ws/](robot_ws/) | The ROS2 (Humble) workspace — all robot code lives here. |
| [robot_ws/README.md](robot_ws/README.md) | Install, build, and run the system. |

## Quick start

```bash
cd robot_ws
# full install steps are in robot_ws/README.md; once ROS2 is set up:
./build.sh && source install/setup.bash
ros2 launch robot_bringup bringup.launch.py
```

