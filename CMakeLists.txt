# cmake最小版本号
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(SDL2Shooter)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})


# 查找SDL2库
find_package(SDL2 REQUIRED)
# 查找SDL2_image库
find_package(SDL2_image REQUIRED)
# 查找SDL2_ttf库
find_package(SDL2_ttf REQUIRED)
# 查找SDL2_mixer库
find_package(SDL2_mixer REQUIRED)


#设置输出目标名称
set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})
# 添加可执行目录
add_executable(${TARGET} src/main.cpp src/Game.cpp)

# 添加链接库
target_link_libraries(${TARGET} PRIVATE SDL2::SDL2 
                                        SDL2_image::SDL2_image 
                                        SDL2_ttf::SDL2_ttf 
                                        SDL2_mixer::SDL2_mixer)   