from setuptools import setup

package_name = 'example_py_pkg'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        # marks this as a ROS2 package so the tools can find it
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='robot-team',
    maintainer_email='fausto.arroyo.mantero@gmail.com',
    description='EXAMPLE Python (ament_python) package — copy this to start your own.',
    license='MIT',
    entry_points={
        'console_scripts': [
            # "<name you type> = <package>.<module>:<function>"
            # this is what makes `ros2 run example_py_pkg example_node` work.
            'example_node = example_py_pkg.example_node:main',
        ],
    },
)
