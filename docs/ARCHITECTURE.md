# ARCHITECTURE - system design

The shared **what**: what this repo currently contains, how the pieces fit
together, and which interfaces people/agents can code against. Keep it matching
reality. The **why** behind a choice goes in [DECISIONS.md](DECISIONS.md).

> **Template status:** this repo is an SDD collaboration template with a ROS2
> starter workspace. Replace the template notes with project-specific design as
> soon as a downstream project has real architecture.

## What This Template Provides

This repo provides a copyable starting structure for multi-agent development:

- a committed shared agent hub: [../AGENTS.md](../AGENTS.md)
- an SDD workflow: [SDD.md](SDD.md)
- tracked spec, plan, and experiment records: [sdd/](sdd/)
- a decision log: [DECISIONS.md](DECISIONS.md)
- a ROS2 Humble starter workspace: [../robot_ws/](../robot_ws/)

## How The Pieces Fit

```text
AGENTS.md
  -> points every person/agent at the same shared rules

docs/ARCHITECTURE.md
  -> current system design and ownership boundaries

docs/SDD.md
  -> when to write specs, plans, and experiments

docs/sdd/
  -> durable feature records for non-trivial work

docs/DECISIONS.md
  -> append-only history of non-obvious choices

robot_ws/
  -> optional ROS2 scaffold for projects that need it
```

## Interfaces And Boundaries

Downstream projects should define real interfaces here as soon as they exist:
APIs, topics, messages, data formats, config contracts, model inputs/outputs,
or package boundaries.

Until then, use these template rules:

- Each person/agent owns one area at a time.
- New work should be added behind a documented interface.
- Shared interfaces are changed only through the SDD flow.
- Other areas consume outputs; they do not depend on private internals.

## Codebase Today

The repo ships a ROS2 Humble workspace under [robot_ws/](../robot_ws/) as a
starter. It includes Python, C++, and C package examples plus a bringup package.
It is a scaffold, not a required architecture decision. To build on it, see
[HOW_TO_ROS2.md](HOW_TO_ROS2.md).

## Components - Who Owns What

One row per area as work is claimed. Keep it honest: only list what exists or is
actively being built.

| Area / package | Owner | Provides | Depends on | Status |
|---|---|---|---|---|
| `docs/sdd/` | shared | spec, plan, experiment framework | `AGENTS.md` | template |
| `robot_ws/` | shared starter | ROS2 example packages and bringup | ROS2 Humble | optional scaffold |
