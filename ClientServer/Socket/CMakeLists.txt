#Cmake file for static library
cmake_minimum_required (VERSION 3.5.1)

project(Socket)
if (WIN32)
    set(SOURCE_LIB WinSocket/WinSocket.cpp ISocket/ISocket.cpp)	
endif (WIN32)		
if (UNIX)
    set(SOURCE_LIB LinSocket/LinSocket.cpp ISocket/ISocket.cpp)	
endif (UNIX)

add_library(Socket STATIC ${SOURCE_LIB})
