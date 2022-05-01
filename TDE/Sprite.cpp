#include "pch.h"
#include "Sprite.h"
#include "opengl/OpenGLSprite.h"

namespace TDE
{
	Sprite::Sprite(const std::string& file)
	{
#ifdef TDE_OPENGL
		mImplementation = new OpenGLSprite(file);
#else
		#Only_OpenGL_is_supported
#endif // TDE OPENGL

	}

	int Sprite::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int Sprite::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	void Sprite::Bind()
	{
		mImplementation->Bind();
	}
}
