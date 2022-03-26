set(HEADER_FILES
	Core.h
	EntryPoint.h
	GameWindow.h
	TDE.h
	TDEApp.h
	WindowInterface.h
	opengl/WinWindow.h
	)

set(SOURCE_FILES
	GameWindow.cpp
	opengl/WinWindow.cpp
	TDEApp.cpp
	)

add_library(TDE SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DTDE_LIB)
add_definitions(-DTDE_DEBUG)

include_directories(../glfw/include)
include_directories(../TDE)

target_precompile_headers(TDE PRIVATE pch.h)

target_link_libraries(TDE glfw)