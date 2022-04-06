#pragma once

#include "SpriteImplementation.h"

namespace TDE
{
	class Sprite
	{
	public:
		Sprite(const std::string& file);

		int GetWidth() const;
		int GetHeight() const;

		void Bind();

	private:
		SpriteImplementation* mImplementation;
	};
}
