# AGENTS.md — read this first

Entry point for anyone working in this repo. This file is deliberately short and kept lean: it says
*where each kind of information lives* and *how to work here without colliding*.
It is not the place for design detail — that goes in the docs below.

## Where information lives — go to the right file

| You need… | It's in… |
|---|---|
| How we work together (this) | `AGENTS.md` |
| What we're building + how the pieces fit | [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) |
| Why a past choice was made (the history) | [docs/DECISIONS.md](docs/DECISIONS.md) |
| Install / build / run | [robot_ws/README.md](robot_ws/README.md) |
| Working with the ROS2 starter templates (new to ROS2? start here) | [docs/HOW_TO_ROS2.md](docs/HOW_TO_ROS2.md) |
| Repo map + quick start | [README.md](README.md) |

Keep every doc **lean** — add detail when it becomes real, not before.

## If you're working here with an AI assistant

This file (`AGENTS.md`, at the repo root) is the single shared source of truth —
don't copy its contents anywhere.

The repo *is* the shared memory — anything not written down isn't shared. So:

1. **Read [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) before coding** so your work fits the current design.
2. **Add alongside others' work; don't edit it.** (In the ROS2 scaffold that means a new node/package — see [docs/HOW_TO_ROS2.md](docs/HOW_TO_ROS2.md).)
3. **Changed the design?** → update [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md).
4. **Made a non-obvious choice?** → one line in [docs/DECISIONS.md](docs/DECISIONS.md): `date — what — why`.

## Setting up your own AI tool — what's personal vs shared

This file is committed and read by the whole team, so **nothing personal goes here.**
Put your personal preferences in your tool's *own* config so teammates don't inherit them:

| Tool | Your personal config lives in |
|---|---|
| Claude Code | `~/.claude/CLAUDE.md` (applies to all your projects, not committed) |
| Cursor | user-level rules (in settings) |
| Codex / other | that tool's user config |

Rule of thumb: **would a teammate on another machine need this to be true?**
Yes → it belongs in the repo. Only you care → your personal config.

- **Personal** (keep out of the repo): how you like commits handled, "don't add me as co-author", editor habits, your name.
- **Shared** (belongs in the repo): the design + interfaces, "add alongside, don't edit others'", "log decisions".
