cmake_minimum_required (VERSION 3.5.1)

project(FileSearch)

if (WIN32)
    set(SOURCE_LIB WinFileSearch/WinFileSearch.cpp)		
endif (WIN32)		
if (UNIX)
    set(SOURCE_LIB LinFileSearch/LinFileSearch.cpp)	
endif (UNIX)

add_library(FileSearch STATIC ${SOURCE_LIB})
