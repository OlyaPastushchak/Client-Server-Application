
cmake_minimum_required (VERSION 3.5.1)

# Include sub-projects.
set(CMAKE_CXX_FLAGS "-Wall")

set (CMAKE_CXX_STANDARD "14")

set(CMAKE_CXX_STANDARD_REQUIRED ON) 

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -no-pie")
add_subdirectory (Client)

add_subdirectory(Server)

add_subdirectory(Socket)