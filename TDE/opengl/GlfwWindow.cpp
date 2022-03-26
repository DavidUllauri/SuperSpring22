#include "pch.h"

#include "GlfwWindow.h"
#include "Core.h"

namespace TDE
{
	GlfwWindow::GlfwWindow()
	{
		if (!glfwInit())
			TDE_LOG("ERROR: Initialization failed");
	}

	bool GlfwWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		m_Window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		if (!m_Window) {
			TDE_LOG("ERROR: window creation failed!");
			return false;
		}
		else {
			glfwMakeContextCurrent(m_Window);
			return true;
		}
	}

	void GlfwWindow::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}

	void GlfwWindow::PollEvents()
	{
		glfwPollEvents();
	}

	int GlfwWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(m_Window, &width, &height);

		return width;
	}

	int GlfwWindow::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(m_Window, &width, &height);

		return height;
	}

	GlfwWindow::~GlfwWindow()
	{
		if(m_Window != nullptr)
			glfwDestroyWindow(m_Window);

		glfwTerminate();
	}

}