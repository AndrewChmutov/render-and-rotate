cmake_minimum_required(VERSION 3.25)
project(RenderRotate)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(include)

add_executable(RenderRotate src/main.cpp)
target_link_libraries(RenderRotate ${SDL2_LIBRARIES})