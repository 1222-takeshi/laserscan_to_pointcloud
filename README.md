# laserscan_to_pointcloud
This package is ROS 2 package.

This package can convert /scan (sensor_msgs::msg::LaserScan) to /pointcloud (sensor_msgs::msg::PointCloud2) .

## Performed environment
Ubuntu 22.04 / ROS 2 Humble

## How to Run
``` sh
ros2 launch laser_to_pointcloud laser_to_pointcloud_launch.xml
```
