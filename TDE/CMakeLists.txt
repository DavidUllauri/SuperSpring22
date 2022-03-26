set(HEADER_FILES
	TDE.h
	TDEApp.h
	Core.h
	GameWindow.h
	WindowInterface.h
	specificGLFW/GlfwWindow.h
	)

set(SOURCE_FILES
	TDEApp.cpp
	GameWindow.cpp
	specificGLFW/GlfwWindow.cpp
	)

add_library(TDE SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DTDE_LIB)
add_definitions(-DTDE_DEBUG)

include_directories(../glfw/include)
include_directories(../TDE)

target_precompile_headers(TDE PRIVATE pch.h)

target_link_libraries(TDE glfw)