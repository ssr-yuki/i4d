cmake_minimum_required(VERSION 3.1)
project(i4d)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O2 -Wall")

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

add_library(i4dsocket
  ${PROJECT_SOURCE_DIR}/src/socket_base.cpp
  ${PROJECT_SOURCE_DIR}/src/socket_ipv4.cpp
)
