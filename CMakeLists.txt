# cmake最小版本号
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(SDL2Shooter)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

#设置输出目标名称
set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})
# 添加可执行目录
add_executable(${TARGET} src/main.cpp)