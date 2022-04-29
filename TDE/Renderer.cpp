#include "pch.h"
#include "Renderer.h"
#include "GameWindow.h"
#include "opengl/OpenGLRenderer.h"

namespace TDE
{
	void Renderer::Init()
	{
		if (mInstance == nullptr)
			mInstance = new Renderer;
	}

	void Renderer::Draw(Sprite& image, int xPos, int yPos, int zPos)
	{
		assert(mInstance);

		mInstance->mRenderer->Draw(image, xPos, yPos, zPos, mInstance->mShader);
	}

	Renderer::Renderer():
		mShader("../TDE/assets/shaders/VertexShaderDefault.glsl", "../TDE/assets/shaders/FragShaderDefault.glsl")
	{
#ifdef TDE_OPENGL
		mRenderer = new OpenGLRenderer;
#else
		#Only_OpenGL_is_supported;
#endif // TDE OPENGL
	}

}