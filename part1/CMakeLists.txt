cmake_minimum_required( VERSION 3.0 )

project( lab1part1 )

set(CMAKE_CXX_FLAGS "-g -O3")

#met(CMAKE_CURRENT_SOURCE_DIR CMAKE_CURRENT_LIST_DIR)

add_executable( lab1part1
  main.cpp
  DataBaseArray.cpp
  DataBaseLinkedList.cpp
)
