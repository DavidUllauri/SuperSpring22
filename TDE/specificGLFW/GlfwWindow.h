#pragma once

#include "WindowImplementation.h"
#include <GLFW/glfw3.h>

namespace TDE
{
	class GlfwWindow : public WindowImplementation
	{
	public:
		GlfwWindow();
		virtual bool CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		~GlfwWindow();

	private:
		GLFWwindow* mGlfwWindow{ nullptr };
	};
}