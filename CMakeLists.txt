cmake_minimum_required(VERSION 3.22)
project(OpenGL)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)


add_subdirectory(src)
