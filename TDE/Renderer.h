#pragma once

#include "Sprite.h"
#include "Shader.h"
#include "RendererInterface.h"

namespace TDE
{
	class Renderer
	{
	public:
		static void Init();
		static void Draw(Sprite& image, int xPos, int yPos, int zPos);
	private:
		inline static Renderer* mInstance{ nullptr };
		RendererInterface* mRenderer{ nullptr };

		Renderer();

		Shader mShader;
	};
}
