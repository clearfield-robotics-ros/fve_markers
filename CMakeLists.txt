cmake_minimum_required(VERSION 2.8.3)
project(fve_markers)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp visualization_msgs std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(fve_markers_node src/fve_markers_node.cpp)
target_link_libraries(fve_markers_node ${catkin_LIBRARIES})