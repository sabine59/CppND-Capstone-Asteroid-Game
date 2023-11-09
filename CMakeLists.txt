cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED COMPONENTS SDL2)
add_executable(AsteroidGame src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/ufo.cpp src/celestrial_body.cpp src/asteroid.cpp)
target_link_libraries(AsteroidGame PRIVATE SDL2::SDL2)
