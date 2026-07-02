# Agentic Workflows Template

A copyable starter for specification-driven development with multiple people and
multiple coding agents. The repo gives you a shared agent hub, a spec -> plan ->
experiment workflow, a decision log, and an optional ROS2 Humble workspace.

## Repo Map

| Path | What it is |
|---|---|
| [AGENTS.md](AGENTS.md) | **Start here** - shared instructions for Codex, Claude Code, and people. |
| [docs/AGENT_SETUP.md](docs/AGENT_SETUP.md) | How to point local agent prompts at `AGENTS.md`. |
| [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) | Current system design, interfaces, and ownership table. |
| [docs/SDD.md](docs/SDD.md) | Spec -> plan -> experiment workflow and gates. |
| [docs/sdd/](docs/sdd/) | Templates and tracked feature records. |
| [docs/DECISIONS.md](docs/DECISIONS.md) | Append-only decision log: what changed and why. |
| [docs/HOW_TO_ROS2.md](docs/HOW_TO_ROS2.md) | ROS2 starter guide. |
| [robot_ws/](robot_ws/) | Optional ROS2 Humble starter workspace. |
| [robot_ws/README.md](robot_ws/README.md) | Install, build, and run the ROS2 scaffold. |

## Use This As A New Project Template

1. Copy the files into your target repo.
2. Keep `AGENTS.md`, `docs/`, and `docs/sdd/` tracked.
3. Create local agent prompt adapters if needed:
   - Claude Code: `.claude/CLAUDE.md` with `@../AGENTS.md`
   - Codex: use the root `AGENTS.md`
4. Add the commented agent-ignore lines from `.gitignore` to the target repo if
   you want local prompt/config files to stay private.
5. Replace the template parts of `docs/ARCHITECTURE.md` with your actual system
   design.
6. For the first real feature, copy the SDD templates and create matching spec,
   plan, and experiment records.

## SDD Quick Start

Tiny change? Make it, then add a decision log line only if the reason is not
obvious.

Big feature? Use the full flow:

```text
spec -> human approval -> plan -> human approval -> implementation -> experiment/validation
```

Start from:

- `docs/sdd/specs/TEMPLATE.md`
- `docs/sdd/plans/TEMPLATE.md`
- `docs/sdd/experiments/TEMPLATE.md`

## ROS2 Quick Start

The ROS2 workspace is optional. If your project needs it:

```bash
cd robot_ws
./build.sh
source install/setup.bash
ros2 launch robot_bringup bringup.launch.py
```

Full setup is in [robot_ws/README.md](robot_ws/README.md).
