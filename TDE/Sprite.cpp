#include "pch.h"
#include "Sprite.h"
#include "opengl/OpenGLSprite.h"

namespace TDE
{
	Sprite::Sprite(const std::string& file)
	{
		mImplementation = new OpenGLSprite(file);
	}

	int Sprite::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int Sprite::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

}