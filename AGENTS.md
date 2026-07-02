# AGENTS.md - shared agent hub

Entry point for people and AI agents working in this repo. Keep this file lean:
it should say where information lives, what must be read before coding, and how
to avoid collisions. Detailed design, plans, and run notes belong in the docs
linked below.

## Start Here

1. Read [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) to understand the current
   system and ownership boundaries.
2. Read [docs/SDD.md](docs/SDD.md) before non-trivial work. It defines the
   spec -> plan -> experiment workflow.
3. Check existing feature records under [docs/sdd/](docs/sdd/) before changing
   related behavior.
4. If you are applying this template to another repo, read
   [docs/ADOPTING.md](docs/ADOPTING.md) and rewrite placeholders from target
   repo facts only.

## Where Information Lives

| You need... | It is in... |
|---|---|
| Shared agent/person entry point | `AGENTS.md` |
| Current system design and interfaces | [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) |
| Apply this template to another repo | [docs/ADOPTING.md](docs/ADOPTING.md) |
| SDD workflow and gates | [docs/SDD.md](docs/SDD.md) |
| Feature specs, implementation plans, experiments | [docs/sdd/](docs/sdd/) |
| Non-obvious choices and history | [docs/DECISIONS.md](docs/DECISIONS.md) |
| Repo map and copy instructions | [README.md](README.md) |

Keep every doc lean. Add detail when it becomes real, not before.

## Collaboration Rules

**One area per person/agent.** Claim or create an area in the Components table in
[docs/ARCHITECTURE.md](docs/ARCHITECTURE.md). If you need something from another
area, consume its documented output or interface instead of reaching into its
implementation.

For AI agents:

1. Treat the repo as shared memory. If it is not written down, it is not shared.
2. Add alongside others' work by default. That usually means a new module,
   package, or component behind a documented interface.
3. For a new big feature, follow [docs/SDD.md](docs/SDD.md): draft a spec, wait
   for human approval, draft a plan, wait for human approval, implement, then
   record the experiment or validation result.
4. If you change the system design or interface, update
   [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md).
5. If you make a non-obvious choice, add one line to
   [docs/DECISIONS.md](docs/DECISIONS.md): `YYYY-MM-DD - area - what - why`.
6. Do not commit, push, delete generated results, launch long external jobs, or
   perform irreversible actions unless the user explicitly asks.

## What Counts As Big Work

Use the full SDD flow when a change touches two or more modules, changes a public
interface, changes data/model/config contracts, adds a new algorithm, or affects
more than one person/agent's area.

Tiny fixes can skip specs and plans. If the reason is not obvious, log it in
`docs/DECISIONS.md`. Pure research or tuning probes should at least record an
experiment.

## Personal Vs Shared Agent Config

This file is committed and shared by the whole team. Tool-specific prompt files
should be local adapters that point here, not places where shared project truth
is duplicated.

| Tool | Recommended local adapter |
|---|---|
| Codex | Uses root `AGENTS.md` as the shared repo instructions |
| Claude Code | `.claude/CLAUDE.md` containing only `@../AGENTS.md` |
| Other agents | A local project prompt that says to read `AGENTS.md` first |

Personal preferences stay out of the repo: commit style, editor habits, names,
local model/provider settings, secrets, and machine-specific paths.
