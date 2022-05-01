#pragma once

#include "SpriteInterface.h"
#include "Core.h"

namespace TDE
{
	class TDE_API Sprite
	{
	public:
		Sprite(const std::string& file);

		int GetWidth() const;
		int GetHeight() const;

		void Bind();

	private:
		SpriteInterface* mImplementation;
	};
}
