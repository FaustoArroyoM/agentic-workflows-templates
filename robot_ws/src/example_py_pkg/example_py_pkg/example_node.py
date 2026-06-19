#!/usr/bin/env python3
"""
EXAMPLE Python node (ament_python).

A tiny, fully working node that shows the three things almost every node does:
  - PUBLISH on a topic
  - SUBSCRIBE to a topic
  - run code periodically on a TIMER

It publishes and subscribes to the SAME topic, so when you run it you immediately
see it hearing its own messages -- proof the wiring works.

==========================================================================
HOW TO MAKE YOUR OWN NODE FROM THIS:
  1. Copy this file:  example_py_pkg/my_node.py
  2. Rename the class and the string in super().__init__('...').
  3. Change the topic names + message types to the ones in Claude.md.
  4. Register it in setup.py under console_scripts:
       'my_node = example_py_pkg.my_node:main',
  5. From robot_ws/:  ./build.sh  &&  source install/setup.bash
  6. Run it:          ros2 run example_py_pkg my_node
==========================================================================
"""
import rclpy
from rclpy.node import Node

# import the message type(s) you need. std_msgs/String here; for the real
# topics see Claude.md (sensor_msgs/Image, vision_msgs/Detection2DArray, ...).
from std_msgs.msg import String


class ExampleNode(Node):
    def __init__(self):
        super().__init__('example_node')          # the node's name

        # PUBLISHER: (message type, topic name, queue size)
        self.pub = self.create_publisher(String, '/example_chatter', 10)

        # SUBSCRIBER: (message type, topic name, callback, queue size)
        self.sub = self.create_subscription(String, '/example_chatter', self.on_msg, 10)

        # TIMER: call self.tick() every 0.5 s (2 Hz)
        self.timer = self.create_timer(0.5, self.tick)
        self.count = 0

        self.get_logger().info('example_node started ✓')

    def tick(self):
        """Periodic work goes here. Build a message and publish it."""
        msg = String()
        msg.data = f'hello {self.count}'
        self.pub.publish(msg)
        self.count += 1

    def on_msg(self, msg):
        """Runs every time a message arrives on the subscribed topic.
        Keep callbacks fast: no sleep(), no blocking work here."""
        self.get_logger().info(f'heard: {msg.data}')


def main(args=None):
    rclpy.init(args=args)
    node = ExampleNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
