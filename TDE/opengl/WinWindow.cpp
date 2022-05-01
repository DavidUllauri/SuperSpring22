#include "pch.h"

#include "WinWindow.h"
#include "Core.h"

namespace TDE
{
	WinWindow::WinWindow()
	{
		if (!glfwInit())
			TDE_LOG("ERROR: Initialization failed");
	}

	bool WinWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		m_window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		if (!m_window) {
			TDE_LOG("ERROR: window creation failed!");
			return false;
		}

		glfwMakeContextCurrent(m_window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			TDE_LOG("ERROR: Failed to initialize GLAD");

		return true;
	}

	void WinWindow::SwapBuffers()
	{
		glfwSwapBuffers(m_window);
	}

	void WinWindow::PollEvents()
	{
		glfwPollEvents();
	}

	int WinWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(m_window, &width, &height);

		return width;
	}

	int WinWindow::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(m_window, &width, &height);

		return height;
	}

	WinWindow::~WinWindow()
	{
		if(m_window != nullptr)
			glfwDestroyWindow(m_window);

		glfwTerminate();
	}

}