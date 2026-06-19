# ARCHITECTURE — the system design (living document)

The shared **what**: what we're building and how the pieces fit together — the
picture everyone codes against. Keep it matching reality. The **why** behind a
change goes in [DECISIONS.md](DECISIONS.md).

> **Status: early — little is decided yet.** Fill each section in as real
> decisions land. An empty heading is better than a guess; don't document
> hardware, interfaces, or components that don't exist yet.

## What we're building

_One short paragraph once the goal is agreed. (TBD.)_

## How the pieces fit

How the parts of the system talk to each other — the **interfaces** between
people's work. These are the one thing that must stay stable, so define them here
as they're agreed and tell the team before changing one.

_TBD._

## The codebase today

The repo ships a **ROS2 (Humble) workspace** under [robot_ws/](../robot_ws/) as a
starting point, with example packages to copy from. It's a scaffold, not a final
decision. To build on it, see [HOW_TO_ROS2.md](HOW_TO_ROS2.md).

## Components — who owns what

One row per area as work is claimed. Keep it honest — only list what exists.

| Area / package | Owner | Provides | Depends on | Status |
|---|---|---|---|---|
| _example_ | _—_ | _—_ | _—_ | template only |
