cmake_minimum_required(VERSION 3.14)

project(laser_to_pointcloud)

find_package(ament_cmake_auto REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(pcl_conversions REQUIRED)

ament_auto_find_build_dependencies()

# ソースコードを追加する

ament_auto_add_executable(laser_to_pointcloud
  src/laser_to_pointcloud_node.cpp
  src/laser_to_pointcloud.cpp
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

# ament_cmake_auto パッケージを使用して install の設定を行う
ament_auto_package(
  INSTALL_TO_SHARE
  launch
)
