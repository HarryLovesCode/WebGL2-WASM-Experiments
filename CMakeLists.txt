cmake_minimum_required(VERSION 2.8)

project(opengl)

add_executable(
    opengl
    src/main.c
    src/util.c
    src/loader.c
    src/vector.c
    src/camera.c
    src/matrix.c
    src/callbacks.c
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -O3")

find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GLEW REQUIRED glew)

include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

target_link_libraries(opengl -lm ${GLEW_LIBRARIES} ${GLFW_LIBRARIES})
