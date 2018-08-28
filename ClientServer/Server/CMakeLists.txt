#Cmake file for Server
cmake_minimum_required (VERSION 3.5.1)

project(Server)

set(SOURCE_EXE main.cpp Server.cpp)

add_executable (Server ${SOURCE_EXE})

target_link_libraries(Server Socket)