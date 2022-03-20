#pragma once

#include "WindowImplementation.h"

namespace TDE
{
	class GameWindow
	{
	public:
		static void Init();
		static GameWindow* GetWindow();

		bool CreateWindow(int width, int height, const std::string& windowName);
		void SwapBuffers();
		void PollEvents();	// Prof calls it CollectEvents()
		int GetWidth() const;
		int GetHeight() const;

	private:
		inline static GameWindow* mInstance{ nullptr };

		GameWindow();

		WindowImplementation* mWindow{ nullptr };
	};
}
