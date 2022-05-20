#pragma once

#include "WindowInterface.h"
#include "Core.h"
#include "Events.h"

namespace TDE
{
	class TDE_API GameWindow
	{
	public:
		static void Init();
		static GameWindow* GetWindow();

		bool CreateWindow(int width, int height, const std::string& windowName);
		void SwapBuffers();
		void PollEvents();	// Prof calls it CollectEvents()
		int GetWidth() const;
		int GetHeight() const;
		
		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)> keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)> keyReleasedCallback);

		bool WindowShouldClose();

	private:
		inline static GameWindow* mInstance{ nullptr };

		GameWindow();

		WindowInterface* mWindow{ nullptr };
	};
}
