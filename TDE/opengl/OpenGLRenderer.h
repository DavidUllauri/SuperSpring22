#pragma once

#include "RendererInterface.h"

namespace TDE
{
	class OpenGLRenderer: public RendererInterface
	{
		virtual void Draw(Sprite& image, int xPos, int yPos, int zPos, Shader shader) override;
	};
}