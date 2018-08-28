#Cmake file for Client
cmake_minimum_required (VERSION 3.5.1)

project(Client)


set(SOURCE_EXE main.cpp Client.cpp)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

endif()

include_directories(FileSearch)
add_executable (Client ${SOURCE_EXE})
add_subdirectory(FileSearch)

target_link_libraries(Client Socket)
target_link_libraries(Client FileSearch)
