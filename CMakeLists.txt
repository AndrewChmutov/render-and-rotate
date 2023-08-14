cmake_minimum_required(VERSION 3.25)
project(RenderRotate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(RenderRotate src/main.cpp src/screen.cpp)
target_link_libraries(RenderRotate ${SDL2_LIBRARIES})