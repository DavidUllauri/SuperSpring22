#include "pch.h"

#include "GlfwWindow.h"
#include "TDEUtil.h"

namespace TDE
{
	GlfwWindow::GlfwWindow()
	{
		if (!glfwInit())
			TDE_LOG("ERROR: Initialization failed");
	}

	bool GlfwWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mGlfwWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		if (!mGlfwWindow) {
			TDE_LOG("ERROR: window creation failed!");
			return false;
		}
		else {
			glfwMakeContextCurrent(mGlfwWindow);
			return true;
		}
	}

	void GlfwWindow::SwapBuffers()
	{
		glfwSwapBuffers(mGlfwWindow);
	}

	void GlfwWindow::PollEvents()
	{
		glfwPollEvents();
	}

	int GlfwWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);

		return width;
	}

	int GlfwWindow::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);

		return height;
	}

	GlfwWindow::~GlfwWindow()
	{
		if(mGlfwWindow != nullptr)
			glfwDestroyWindow(mGlfwWindow);

		glfwTerminate();
	}

}