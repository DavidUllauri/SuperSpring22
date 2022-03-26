#pragma once

#include "WindowInterface.h"
#include <GLFW/glfw3.h>

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
		~WinWindow();

	private:
		GLFWwindow* m_window{ nullptr };
	};
}