cmake_minimum_required(VERSION 3.11)
project(SnowSimulator)

include_directories(include)
include_directories(D:\\OpenGL\\glad\\include)
include_directories(D:\\OpenGL\\glm)
include_directories(D:\\OpenGL\\glfw\\include)
add_executable(SnowSimulator "main.cpp" "lib/glad.c" "lib/particle.cpp" "lib/shader.cpp" 
							 "lib/environment.cpp" "lib/particle_system.cpp")
target_link_libraries(SnowSimulator D:\\OpenGL\\glfw\\lib-vc2015\\glfw3.lib)