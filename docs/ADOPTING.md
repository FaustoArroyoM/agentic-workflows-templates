# Adopting this template in another repo

Use this when you want an agent or teammate to apply the collaboration structure
from this repo to an existing codebase.

## Goal

This template gives a target repo shared memory for people and coding agents:

- `AGENTS.md` says how to collaborate.
- `docs/ARCHITECTURE.md` records the real system design and ownership boundaries.
- `docs/SDD.md` defines when to use spec -> plan -> experiment.
- `docs/sdd/` stores feature specs, plans, and validation records.
- `docs/DECISIONS.md` records non-obvious choices and why they were made.

The template files are not project truth until they are rewritten from the target
repo. Do not infer architecture from placeholder text.

## Prompt for an agent

```text
Apply the agentic-workflows template to this codebase.

First read the target repo and identify its actual architecture, modules,
commands, tests, and conventions. Then copy or adapt the template files:
AGENTS.md, docs/SDD.md, docs/sdd/ templates, docs/DECISIONS.md, and
docs/ARCHITECTURE.md.

Rewrite docs/ARCHITECTURE.md from target-repo facts only. Mark unknowns as
unknown. Remove template-only or scaffold-only references that do not exist in
this repo. Do not invent ROS2, services, packages, commands, interfaces, or
ownership areas unless they are present in the target repo.
```

## What to copy

Copy these files and directories into the target repo:

- `AGENTS.md`
- `docs/ADOPTING.md`
- `docs/AGENT_SETUP.md`
- `docs/ARCHITECTURE.md`
- `docs/DECISIONS.md`
- `docs/SDD.md`
- `docs/sdd/`

Then edit them in place for the target repo.

## What to rewrite immediately

Rewrite these sections before using the target repo for real work:

- `README.md` repo map, if you copy it at all.
- `docs/ARCHITECTURE.md` template status, system overview, interfaces, and
  components table.
- `AGENTS.md` links to optional technology guides that the target repo does not
  have.

Keep placeholder text only when it is clearly labeled as a placeholder.

## What to remove

Remove references to optional scaffolds that are not present in the target repo,
such as a ROS2 workspace, frontend app, service template, hardware guide, or
generated example package.

Do not keep dead links as reminders. Put future ideas in a spec, plan, or
decision only when they become real.

## First downstream commit

The first adoption commit should usually do only this:

1. Add the shared agent/docs structure.
2. Rewrite architecture from existing repo facts.
3. Add one decision line explaining why the template was adopted.
4. Leave product or feature changes for a later spec/plan.
