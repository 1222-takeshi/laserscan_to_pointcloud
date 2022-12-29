#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <pcl_conversions/pcl_conversions.h>

#include "laser_to_pointcloud/laser_to_pointcloud.hpp"

LaserToPointcloud::LaserToPointcloud()
: Node("laser_to_pointcloud")
{
  // LaserScan メッセージを受信するサブスクライバを作成
  laser_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
    "/scan", rclcpp::QoS(rclcpp::SensorDataQoS()),
    std::bind(&LaserToPointcloud::laser_callback, this, std::placeholders::_1));

  // PointCloud2 メッセージを送信するパブリッシャを作成
  pointcloud_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("/pointcloud", 10);
}

// LaserScan メッセージを受信したときに呼び出されるコールバック関数
void LaserToPointcloud::laser_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
{
  // LaserScan メッセージを PointCloud2 メッセージに変換
  sensor_msgs::msg::PointCloud2 pointcloud;
  // LaserScan メッセージを座標系 "base_link" 上での PointCloud2 メッセージに変換
  // PointCloud2 メッセージを作成
  pcl::PointCloud<pcl::PointXYZ> cloud;
  cloud.width = msg->ranges.size();
  cloud.height = 1;
  cloud.points.resize(cloud.width);
  // LaserScan メッセージから PointCloud2 メッセージへの変換
  for (std::size_t i = 0; i < msg->ranges.size(); ++i) {
    cloud.points[i].x = msg->ranges[i] * std::cos(msg->angle_min + msg->angle_increment * i);
    cloud.points[i].y = msg->ranges[i] * std::sin(msg->angle_min + msg->angle_increment * i);
    cloud.points[i].z = 0.0;
  }
  // PointCloud2 メッセージに変換
  pcl::toROSMsg(cloud, pointcloud);
  pointcloud.header.frame_id = "base_link";
  pointcloud.header.stamp = msg->header.stamp;
  pointcloud_pub_->publish(pointcloud);
}
