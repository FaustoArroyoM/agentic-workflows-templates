# DEVELOPING — how to build on these templates

For teammates who have **never used ROS2**. Read [../Claude.md](../Claude.md) once
for the big picture (the mission + the agreed topic map), then use this for the
day-to-day. [README.md](README.md) covers install + how to run.

---

## The mental model (2 minutes)

- A **node** is one small program that does one job (read the camera, run YOLO,
  drive the motors…).
- Nodes never import each other. They talk over named **topics** — a node
  *publishes* messages on a topic, other nodes *subscribe* to it. Think shared
  chat channels.
- The **contract** is just `(topic name, message type)`. As long as everyone
  uses the names in Claude.md's topic map, your node and mine connect at runtime
  with zero shared code.
- A **package** is a folder of related nodes (one per person/area keeps us out of
  each other's way). A **launch file** starts many nodes at once.

That's it. You can build a useful node knowing only this.

---

## Your daily loop

```bash
# do this ONCE per terminal
source /opt/ros/humble/setup.bash
source install/setup.bash        # after you've built at least once

# edit your node, then:
./build.sh                       # rebuild (Python: only needed after setup.py changes)
ros2 run <your_pkg> <your_node>  # run just yours
```

### Make a new node (Python)
1. Copy `src/example_py_pkg/example_py_pkg/example_node.py` → `my_node.py`.
2. Rename the class and the `super().__init__('...')` name.
3. Change the topics + message types to the ones in Claude.md.
4. Register it in `src/example_py_pkg/setup.py` under `console_scripts`:
   `'my_node = example_py_pkg.my_node:main',`
5. `./build.sh && source install/setup.bash`, then `ros2 run example_py_pkg my_node`.

### Make a new node (C++)
1. Copy `src/example_cpp_pkg/src/example_node.cpp` → `my_node.cpp`.
2. Rename the class and the `Node("...")` name; change topics + types.
3. In `src/example_cpp_pkg/CMakeLists.txt` add:
   `add_executable(my_node src/my_node.cpp)` +
   `ament_target_dependencies(my_node rclcpp std_msgs)` +
   `install(TARGETS my_node DESTINATION lib/${PROJECT_NAME})`.
4. `./build.sh && source install/setup.bash`, then `ros2 run example_cpp_pkg my_node`.

### Make a whole new package (your own area)
```bash
cd src
ros2 pkg create --build-type ament_python perception --dependencies rclpy sensor_msgs
# or, for C++:
ros2 pkg create --build-type ament_cmake  control    --dependencies rclcpp geometry_msgs
```
Then add nodes to it exactly like the examples. Add your new package's name to
`robot_bringup/package.xml` and `robot_bringup/launch/bringup.launch.py` so it
starts with everything else.

---

## Testing your node without anyone else's code

You don't need the camera or the full system to test your node — fake its inputs:

```bash
# see what's running and connected
ros2 node list
ros2 topic list
rqt_graph

# watch your node's OUTPUT
ros2 topic echo /person_count

# fake your node's INPUT (publish a test message by hand)
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.2}}"

# is data actually flowing, and how fast?
ros2 topic hz /scan

# inspect a message type's fields (the real API — read this before coding)
ros2 interface show vision_msgs/msg/Detection2DArray
```

---

## Dependencies — how we manage them

This trips up newcomers because ROS2 has **two** dependency systems. Use the
right one for each kind:

### 1. ROS2 packages → `package.xml` + `rosdep`
Anything that is itself a ROS package — `rclpy`, `rclcpp`, `sensor_msgs`,
`geometry_msgs`, `cv_bridge`, `vision_msgs`, `slam_toolbox`, a LiDAR driver, …

Declare it in your package's `package.xml`:
```xml
<depend>vision_msgs</depend>          <!-- C++: build + run -->
<exec_depend>cv_bridge</exec_depend>  <!-- Python: run-time only -->
```
Then anyone can install **all** declared deps for the whole workspace at once:
```bash
rosdep install --from-paths src --ignore-src -r -y
```
This is the ROS-native way. It means a teammate cloning the repo runs one command
and gets everything — no guessing.

### 2. Pure-Python libraries → `requirements.txt`
Things on PyPI that are NOT ROS packages — e.g. `ultralytics` (YOLO). Add them to
[requirements.txt](requirements.txt) and `pip install -r requirements.txt`. See
the policy at the top of that file (add when you use it, don't pin until it
breaks).

> Many common libs (OpenCV, NumPy) are *also* available through rosdep keys
> (`python3-opencv`, `python3-numpy`) and are pulled in by ROS packages like
> `cv_bridge`. Prefer that route when it exists — it avoids pip-vs-apt version
> clashes. Reach for pip only for things rosdep can't give you.

### 3. Third-party C++ libraries → CMake
For a non-ROS C++ lib, find it and link it in `CMakeLists.txt`:
```cmake
find_package(OpenCV REQUIRED)
target_link_libraries(my_node ${OpenCV_LIBS})
```

### 4. Another team's ROS package → drop it in `src/`
To use an existing ROS2 package that isn't apt-installable, clone it into `src/`
and `./build.sh` builds it alongside ours:
```bash
cd src && git clone <repo-url>
```

### About virtualenvs + `requirements.txt` before we know the hardware
- **Don't wrap ROS2 in a fresh venv.** ROS2's Python (rclpy etc.) lives in the
  system interpreter; a clean venv won't see it and you'll fight import errors.
  Use the system Python; `pip install --user` or plain `pip install` is fine on
  the Pi/dev machine. (If you insist on a venv, create it with
  `--system-site-packages`.)
- **Yes, keep `requirements.txt` now.** It's just the agreed home for pip deps.
  It stays nearly empty until we adopt a library — that's expected, not a smell.
- **Hold off on hardware SDKs** (`depthai`, `pyrealsense2`, `RPi.GPIO`, …) until
  we've actually picked the device. They're marked optional/per-device in
  requirements.txt so nobody without the hardware has to install them.

---

## House rules (keep us conflict-free during the hackathon)

- **One package per person/area.** Don't edit someone else's node — write a new
  one that subscribes to their topic.
- **Don't rename a topic** from Claude.md's map. Need a new topic? Add it to the
  map in Claude.md and tell the team first.
- **Keep callbacks fast** — no `sleep()` / blocking I/O inside a subscriber
  callback. Use a timer for periodic work.
- **`ros2 interface show <type>` before you code** against a message — the field
  names are the real API.
- **Commit your own work.** (And per repo policy, do the commits yourself.)

---

## When it doesn't work — the usual suspects

| Symptom | Cause / fix |
|---|---|
| `package not found` / `executable not found` | forgot `source install/setup.bash` in this terminal, or forgot `./build.sh` after a `setup.py`/CMake change |
| topic is listed but `echo` shows nothing | QoS mismatch on a sensor stream — subscribe with `qos_profile_sensor_data` |
| Python edit didn't take effect | you changed `setup.py`/entry points → must re-run `./build.sh` (plain code edits are live with `--symlink-install`) |
| C++ edit didn't take effect | C++ always needs `./build.sh` to recompile |
| `import rclpy` fails | ROS2 not sourced → `source /opt/ros/humble/setup.bash` |
| two nodes both publish `/cmd_vel` | only one thing may drive the robot — disable the placeholder when the real one is up |
