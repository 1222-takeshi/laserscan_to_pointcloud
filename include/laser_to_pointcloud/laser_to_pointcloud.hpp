#ifndef LASER_TO_POINTCLOUD__LASER_TO_POINTCLOUD_HPP_
#define LASER_TO_POINTCLOUD__LASER_TO_POINTCLOUD_HPP_

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

class LaserToPointcloud : public rclcpp::Node
{
public:
  explicit LaserToPointcloud();

private:
  void laser_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg);

  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_sub_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud_pub_;
};

#endif // LASER_TO_POINTCLOUD__LASER_TO_POINTCLOUD_HPP_
