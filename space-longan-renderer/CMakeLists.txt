cmake_minimum_required(VERSION 3.19)
project(space-longan-renderer C CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB APP_SOURCES source/*.cpp source/*.c)
# file(GLOB APP_HEADERS source/*.hpp source/*.h)

add_library(space-longan-renderer ${APP_SOURCES})

