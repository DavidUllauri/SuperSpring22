#pragma once

#include "WindowInterface.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "Events.h"

namespace TDE
{
	class WinWindow : public WindowInterface
	{
	public:
		WinWindow();
		virtual bool CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)> keyPressedCallback) override;
		virtual void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)> keyReleasedCallback) override;
		virtual bool WindowShouldClose() override;
		~WinWindow();

	private:
		struct Callbacks {
			std::function<void(const KeyPressedEvent&)> keyPressedCallback{ [](const KeyPressedEvent&) {} };
			std::function<void(const KeyReleasedEvent&)> keyReleasedCallback{ [](const KeyReleasedEvent&) {} };
		} mCallbacks;

		GLFWwindow* m_window{ nullptr };
	};
}