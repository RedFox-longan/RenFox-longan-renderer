cmake_minimum_required(VERSION 3.19)
project(demo C CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB APP_SOURCES source/*.cpp source/*.c)
# file(GLOB APP_HEADERS source/*.hpp source/*.h)
add_executable(demo ${APP_SOURCES})

# 添加 main.cpp文件启动
# add_executable(space-longan-renderer
#         source/main.cpp
#         )
#
# # GCC 添加库文件
# target_link_libraries(space-longan-renderer
#         mingw32
#         )

# 添加链接库文件(lib)
target_link_libraries(demo space-longan-renderer)

