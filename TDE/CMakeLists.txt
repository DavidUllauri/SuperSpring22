set(HEADER_FILES
	Core.h
	EntryPoint.h
	GameWindow.h
	Renderer.h
	RendererInterface.h
	Shader.h
	ShaderInterface.h
	Sprite.h
	SpriteInterface.h
	TDE.h
	TDEApp.h
	WindowInterface.h
	opengl/OpenGLRenderer.h
	opengl/OpenGLShader.h
	opengl/OpenGLSprite.h
	opengl/WinWindow.h
	)

set(SOURCE_FILES
	GameWindow.cpp
	Renderer.cpp
	Shader.cpp
	Sprite.cpp
	TDEApp.cpp
	opengl/OpenGLRenderer.cpp
	opengl/OpenGLShader.cpp
	opengl/OpenGLSprite.cpp
	opengl/WinWindow.cpp
	)

add_library(TDE SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DTDE_LIB)
add_definitions(-DTDE_DEBUG)
add_definitions(-DTDE_OPENGL)

include_directories(../glfw/include)
include_directories(../TDE)
include_directories(../stbi)
include_directories(../glad/include)

target_precompile_headers(TDE PRIVATE pch.h)

target_link_libraries(TDE glfw glad stbi)