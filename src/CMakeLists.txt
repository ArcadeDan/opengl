
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME} main.cpp glad.c)

target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw)