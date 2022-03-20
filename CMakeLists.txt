cmake_minimum_required(VERSION 3.16)

project(SuperSpring22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(TDE_WINDOWS)
elseif(APPLE)
	add_definitions(TDE_MACOS)
elseif(UNIX)
	add_definitions(TDE_LINUX)
endif()

add_subdirectory(SuperSpring22)
add_subdirectory(TDE)
add_subdirectory(glfw)