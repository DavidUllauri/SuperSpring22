#pragma once

#include "Sprite.h"
#include "Shader.h"

namespace TDE
{
	class RendererInterface
	{
	public:
		virtual void Draw(Sprite& image, int xPos, int yPos, int zPos, Shader) = 0;
	};
}