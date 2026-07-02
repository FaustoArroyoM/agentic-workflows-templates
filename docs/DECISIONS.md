# DECISIONS - what changed and why

Append-only log for the whole team: people and AI tools. When you make a
non-obvious choice, add a line so the next person or agent knows why, not just
what.

- **Format:** newest at the top - `YYYY-MM-DD - area - what changed - why`
- The current design lives in [ARCHITECTURE.md](ARCHITECTURE.md); this file holds
  only the reasoning.

---

- **2026-06-25 - repo/template - Reframed the repo as an SDD collaboration template.**
  Added `docs/SDD.md`, `docs/sdd/{specs,plans,experiments}/` templates, and
  `docs/AGENT_SETUP.md`; updated `AGENTS.md`, `README.md`, and
  `ARCHITECTURE.md` so the root agent hub points Codex, Claude Code, and people
  at the same shared workflow. *Why:* the repo is meant to be copied into other
  projects as a multi-agent SDD starter, not only as a ROS2 scaffold.

- **2026-06-19 - repo/docs - Moved the ROS2 guide to `docs/HOW_TO_ROS2.md` and slimmed `ARCHITECTURE.md`.**
  `robot_ws/DEVELOPING.md` -> `docs/HOW_TO_ROS2.md` (clearer name, all dev docs
  now live in `docs/`). Stripped the speculative goal/hardware/topic-map from
  `ARCHITECTURE.md` down to a general skeleton; the ROS2 workspace is framed as
  a scaffold, not a committed decision. *Why:* little is decided yet - the docs
  were overfitting to a specific ROS2 design and assuming hardware/topics that
  do not exist.

- **2026-06-19 - repo/docs - Set up the shared docs structure.**
  `AGENTS.md` (repo root) is the entry point for how we collaborate; the system
  design lives in `docs/ARCHITECTURE.md`; this log holds the *why*. Personal AI
  config stays out of the repo. *Why:* teammates use different AI tools and
  should not inherit personal config, but the shared design and interface
  contracts must be committed so everyone sees one source of truth.
