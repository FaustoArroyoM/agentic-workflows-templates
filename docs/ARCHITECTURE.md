# ARCHITECTURE - system design

The shared **what**: what this repo currently contains, how the pieces fit
together, and which interfaces people/agents can code against. Keep it matching
reality. The **why** behind a choice goes in [DECISIONS.md](DECISIONS.md).

> **Template status:** this repo is an SDD collaboration template. Replace the
> template notes with project-specific design as soon as a downstream project has
> real architecture. Do not treat placeholder text as project truth.

## What This Template Provides

This repo provides a copyable starting structure for multi-agent development:

- a committed shared agent hub: [../AGENTS.md](../AGENTS.md)
- an adoption guide for existing codebases: [ADOPTING.md](ADOPTING.md)
- an SDD workflow: [SDD.md](SDD.md)
- tracked spec, plan, and experiment records: [sdd/](sdd/)
- a decision log: [DECISIONS.md](DECISIONS.md)

## How The Pieces Fit

```text
AGENTS.md
  -> points every person/agent at the same shared rules

docs/ARCHITECTURE.md
  -> current system design and ownership boundaries

docs/ADOPTING.md
  -> how to apply the template to another repo without inventing facts

docs/SDD.md
  -> when to write specs, plans, and experiments

docs/sdd/
  -> durable feature records for non-trivial work

docs/DECISIONS.md
  -> append-only history of non-obvious choices
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

This repo currently contains the documentation and template structure only. It
does not ship an application, service, ROS2 workspace, frontend, or package
scaffold.

When this template is copied into a real project, replace this section with a
short factual map of the target codebase.

## Components - Who Owns What

One row per area as work is claimed. Keep it honest: only list what exists or is
actively being built.

| Area / package | Owner | Provides | Depends on | Status |
|---|---|---|---|---|
| `AGENTS.md` | shared | collaboration entry point | docs below | template |
| `docs/ADOPTING.md` | shared | adoption workflow for target repos | template docs | template |
| `docs/sdd/` | shared | spec, plan, experiment framework | `AGENTS.md` | template |
