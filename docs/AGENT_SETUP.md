# Agent setup

Use `AGENTS.md` as the committed shared hub. Tool-specific project prompt files
should be tiny local adapters that point to it.

## Codex

Codex reads repository instructions from `AGENTS.md`. Keep shared project rules
there, not in a private Codex prompt.

Optional local-only prompt files can live under `.codex/` if your Codex setup
uses them. Keep those files gitignored in downstream repos.

## Claude Code

Create a local `.claude/CLAUDE.md` containing only:

```md
@../AGENTS.md
```

That gives Claude Code the same shared instructions as Codex without duplicating
the repo rules.

## Downstream `.gitignore`

This template's `.gitignore` includes commented lines showing what to add in a
repo where you want local agent prompts to remain untracked.

Keep committed:

- `AGENTS.md`
- shared docs under `docs/`
- templates under `docs/sdd/`

Keep local:

- `.claude/CLAUDE.md`
- `.claude/settings.local.json`
- `.codex/*` local prompt/config files
- any file containing personal preferences, secrets, local paths, or provider
  settings
