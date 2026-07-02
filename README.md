# Agentic Workflows Template

A copyable starter for specification-driven development with multiple people and
multiple coding agents. The repo gives you a shared agent hub, a spec -> plan ->
experiment workflow, and a decision log.

## Repo Map

| Path | What it is |
|---|---|
| [AGENTS.md](AGENTS.md) | **Start here** - shared instructions for Codex, Claude Code, and people. |
| [docs/ADOPTING.md](docs/ADOPTING.md) | How to apply this template to another codebase without inventing project facts. |
| [docs/AGENT_SETUP.md](docs/AGENT_SETUP.md) | How to point local agent prompts at `AGENTS.md`. |
| [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) | Current system design, interfaces, and ownership table. |
| [docs/SDD.md](docs/SDD.md) | Spec -> plan -> experiment workflow and gates. |
| [docs/sdd/](docs/sdd/) | Templates and tracked feature records. |
| [docs/DECISIONS.md](docs/DECISIONS.md) | Append-only decision log: what changed and why. |

## Use This As A New Project Template

1. Read [docs/ADOPTING.md](docs/ADOPTING.md).
2. Copy the shared agent/docs files into your target repo.
3. Keep `AGENTS.md`, `docs/`, and `docs/sdd/` tracked.
4. Create local agent prompt adapters if needed:
   - Claude Code: `.claude/CLAUDE.md` with `@../AGENTS.md`
   - Codex: use the root `AGENTS.md`
5. Add the commented agent-ignore lines from `.gitignore` to the target repo if
   you want local prompt/config files to stay private.
6. Replace the template parts of `docs/ARCHITECTURE.md` with actual target-repo
   facts. Do not preserve placeholder architecture as project truth.
7. Remove links to optional scaffolds, tools, or guides that are not present in
   the target repo.
8. For the first real feature, copy the SDD templates and create matching spec,
   plan, and experiment records.

For agent-led adoption, use the prompt in [docs/ADOPTING.md](docs/ADOPTING.md).

## What This Is Not

This repo is not a universal app scaffold and does not imply a ROS2, web,
service, data, or hardware architecture. Add those guides only when the target
repo actually has them.

## Keep These Files Tracked

- `AGENTS.md`
- `docs/AGENT_SETUP.md`
- `docs/ADOPTING.md`
- `docs/ARCHITECTURE.md`
- `docs/DECISIONS.md`
- `docs/SDD.md`
- `docs/sdd/`

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
