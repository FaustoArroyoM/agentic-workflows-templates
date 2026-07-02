# SDD workflow - spec -> plan -> experiment

This repo is a template for specification-driven development with multiple
people and multiple coding agents. The goal is simple: agree on intent before
implementation, make the build steps reviewable, then record whether the change
worked.

## The Three Layers

| Layer | Directory | Answers | Written |
|---|---|---|---|
| Spec | `docs/sdd/specs/` | What are we changing, why, what must stay true? | Before coding |
| Plan | `docs/sdd/plans/` | Which files, tasks, tests, and review checks? | After spec approval, before coding |
| Experiment | `docs/sdd/experiments/` | Did it work, by what evidence, and what is next? | After implementation or research run |

Use the same date and slug across all three layers:
`YYYY-MM-DD-short-feature-name.md`.

Example:

- `docs/sdd/specs/2026-06-25-local-planner-design.md`
- `docs/sdd/plans/2026-06-25-local-planner.md`
- `docs/sdd/experiments/2026-06-25-local-planner.md`

## Routing

| Work | Record |
|---|---|
| Tiny change: typo, one-file bugfix, small config tweak | Just do it. Add a decision log line only if the reason is non-obvious. |
| New feature or refactor touching multiple modules | Full spec -> plan -> implementation -> experiment/validation. |
| Interface, data contract, model/config format, or API change | Full flow, plus update `docs/ARCHITECTURE.md`. |
| Research/tuning probe | At least an experiment record. Add a spec if code beyond config changes. |
| Operational recipe or setup command | Put durable instructions in the relevant README or docs page. |

When unsure, write the spec. It is cheaper than rediscovering hidden
constraints after code exists.

## Human Gates

Agents may draft both documents, but the human owns the two approval gates:

1. **Spec gate:** approve the goal, design direction, options rejected, risks,
   and especially the "What Must Not Change" list.
2. **Plan gate:** approve the file map, task order, validation strategy, and any
   cross-owner impact before implementation begins.

The human also owns success thresholds for experiments. Agents can propose
metrics, but a result only means something if the threshold was agreed before the
run.

## Templates

Start from these files:

- [docs/sdd/specs/TEMPLATE.md](sdd/specs/TEMPLATE.md)
- [docs/sdd/plans/TEMPLATE.md](sdd/plans/TEMPLATE.md)
- [docs/sdd/experiments/TEMPLATE.md](sdd/experiments/TEMPLATE.md)

Do not overwrite the templates. Copy one, rename it with the date/slug pattern,
and fill only sections that are real.

## Index

Add feature records here as they become real.

| Feature | Spec | Plan | Experiment |
|---|---|---|---|
| _example_ | `docs/sdd/specs/YYYY-MM-DD-feature-design.md` | `docs/sdd/plans/YYYY-MM-DD-feature.md` | `docs/sdd/experiments/YYYY-MM-DD-feature.md` |
