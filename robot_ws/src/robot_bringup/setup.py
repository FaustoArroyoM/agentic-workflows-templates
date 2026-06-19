import os
from glob import glob
from setuptools import setup

package_name = 'robot_bringup'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # install every *.launch.py so `ros2 launch robot_bringup ...` finds them
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='robot-team',
    maintainer_email='fausto.arroyo.mantero@gmail.com',
    description='Launch files that start the whole robot with one command.',
    license='MIT',
    entry_points={'console_scripts': []},
)
