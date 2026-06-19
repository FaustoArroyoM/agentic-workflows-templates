# robot_ws — ROS2 workspace for the MTU Hackathon Robot

A clean ROS2 (Humble) workspace. It ships **two example packages** showing how to
add your own code — one **Python**, one **C++** — plus a **bringup** package that
launches everything at once. Copy the example for your language, wire it to the
interfaces in [../docs/ARCHITECTURE.md](../docs/ARCHITECTURE.md), and go.

- New to ROS2? Read [../docs/HOW_TO_ROS2.md](../docs/HOW_TO_ROS2.md) — it's written for you.
- The design + agreed interfaces live in [../docs/ARCHITECTURE.md](../docs/ARCHITECTURE.md); how we work together is in [../AGENTS.md](../AGENTS.md).

> **One-liner mental model:** nodes don't import each other; they *publish* /
> *subscribe* to named **topics**. Keep the topic names and the pieces connect at
> runtime.

---

## 1. What you need installed

| Need | Install |
|---|---|
| ROS2 Humble | <https://docs.ros.org/en/humble/Installation.html> (Ubuntu 22.04) |
| Build tools | `sudo apt install python3-colcon-common-extensions python3-rosdep build-essential` |
| rosdep (first time only) | `sudo rosdep init 2>/dev/null; rosdep update` |

Everything else (message types, drivers) is declared per-package and installed by
`rosdep` in the next step — you don't hand-install them one by one.

---

## 2. Get it running

```bash
# ── one-time per machine ──────────────────────────────────────────────────────
source /opt/ros/humble/setup.bash                      # source ROS2 itself
cd robot_ws
rosdep install --from-paths src --ignore-src -r -y      # install all ROS deps from package.xml
pip install -r requirements.txt                         # install pip deps (mostly empty for now)

# ── build ─────────────────────────────────────────────────────────────────────
./build.sh                                              # = colcon build --symlink-install

# ── activate (do this in EVERY new terminal) ──────────────────────────────────
source install/setup.bash
```

Then run the whole system, or just one node:

```bash
# start everything via the bringup launch file
ros2 launch robot_bringup bringup.launch.py

# …or run a single node while developing yours
ros2 run example_py_pkg example_node       # Python
ros2 run example_cpp_pkg example_node      # C++
```

You should see lines like `heard: hello 7` — a node hearing its own messages.
That confirms ROS2 + the workspace are set up correctly.

---

## 3. Layout

```text
robot_ws/
├── build.sh                       ← one-command build
├── requirements.txt               ← pip dependencies (policy inside)
├── README.md                      ← you are here (install + run)
└── src/
    ├── example_py_pkg/            ← EXAMPLE Python package (ament_python)
    │   ├── setup.py               ←   register nodes here (console_scripts)
    │   └── example_py_pkg/example_node.py
    ├── example_cpp_pkg/           ← EXAMPLE C++ package (ament_cmake)
    │   ├── CMakeLists.txt         ←   register nodes here (add_executable)
    │   └── src/example_node.cpp
    └── robot_bringup/             ← launches the whole system
        └── launch/bringup.launch.py
```

Each folder under `src/` is one ROS2 **package**. One package per person/area is
what keeps us conflict-free.

---

## 4. Adding your code

Copy the example node for your language, rename it, point it at the right topics,
register it (Python: `setup.py`; C++: `CMakeLists.txt`), rebuild, run. Then add it
to `robot_bringup/launch/bringup.launch.py` so it starts with everything else.

Full step-by-step (both languages, plus making a brand-new package) is in
[../docs/HOW_TO_ROS2.md](../docs/HOW_TO_ROS2.md).

---

## 5. Dependencies (short version)

- **ROS packages** (rclpy, sensor_msgs, cv_bridge, a LiDAR driver…) → declare in
  the package's `package.xml`, install with `rosdep install` (step 2). This is
  the canonical ROS way.
- **Pure-pip libraries** (e.g. `ultralytics`) → add to `requirements.txt`.
- Don't pre-add hardware SDKs or pin versions before we need them.

The reasoning, the venv caveat, and third-party/C++ libs are all in
[../docs/HOW_TO_ROS2.md → Dependencies](../docs/HOW_TO_ROS2.md#dependencies--how-we-manage-them).

---

## 6. Debugging without reading code

```bash
ros2 topic list                   # every active topic
ros2 topic echo /example_chatter  # watch live messages on a topic
ros2 topic hz /scan               # is something publishing, and how fast?
rqt_graph                         # visual map of nodes <-> topics
```

**Topic shows up but no data flows?** Usually a QoS mismatch on a sensor stream
(camera/LiDAR) — subscribe with `qos_profile_sensor_data` to match the driver.
