cmake_minimum_required(VERSION 3.19)
project(space-longan-renderer C CXX)

include_directories(include)

file(GLOB APP_SOURCES source/*.cpp source/*.c)
# file(GLOB APP_HEADERS include/*.hpp include/*.h) ${APP_HEADERS}
add_library(space-longan-renderer ${APP_SOURCES})

# 添加链接库文件(lib)
target_link_libraries(space-longan-renderer
        gcc
        opengl32
        )