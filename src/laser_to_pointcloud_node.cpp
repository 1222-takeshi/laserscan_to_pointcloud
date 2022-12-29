#include "rclcpp/rclcpp.hpp"
#include "laser_to_pointcloud/laser_to_pointcloud.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<LaserToPointcloud>();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
