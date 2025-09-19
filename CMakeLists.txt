cmake_minimum_required(VERSION 3.10)
project(GraphSTLDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(graph_basic src/main.cpp)
add_executable(friend_reco src/friend_reco.cpp)
add_executable(task_scheduler src/task_scheduler.cpp)
