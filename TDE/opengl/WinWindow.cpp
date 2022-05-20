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
		GLFW_KEY_LEFT;
		m_window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		if (!m_window) {
			TDE_LOG("ERROR: window creation failed!");
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			TDE_LOG("ERROR: Failed to initialize GLAD");

		glfwSetWindowUserPointer(m_window, &mCallbacks);

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS || action == GLFW_REPEAT) {
					KeyPressedEvent event{ key };
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };
					userPointer->keyPressedCallback(event);
				}
				else if (action == GLFW_RELEASE) {
					KeyReleasedEvent event{ key };
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };
					userPointer->keyReleasedCallback(event);
				}
			}
		);

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

	void WinWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)> keyPressedCallback)
	{
		mCallbacks.keyPressedCallback = keyPressedCallback;
	}

	void WinWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)> keyReleasedCallback)
	{
		mCallbacks.keyReleasedCallback = keyReleasedCallback;
	}

	bool WinWindow::WindowShouldClose()
	{
		return glfwWindowShouldClose(m_window);
	}

}