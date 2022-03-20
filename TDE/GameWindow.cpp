#include "pch.h"
#include "GameWindow.h"
#include "specificGLFW/GlfwWindow.h"

namespace TDE
{
	GameWindow::GameWindow()
	{
#ifdef TDE_WINDOWS
		mWindow = new GlfwWindow;
#elif defined TDE_MACOS
		mWindow = new GlfwWindow;
#elif defined TDE_LINUX
		mWindow = new GlfwWindow;
#else
	#Unsupported_plateform
#endif // TDE_WINDOWS

	}

	void GameWindow::Init()
	{
		if(mInstance == nullptr)
			mInstance = new GameWindow;
	}

	GameWindow* GameWindow::GetWindow()
	{
		assert(mInstance);
		return mInstance;
	}

	bool GameWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		return mWindow->CreateWindow(800, 600, "Super Spring 2022");
	}

	void GameWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void GameWindow::PollEvents()
	{
		mWindow->PollEvents();
	}

	int GameWindow::GetWidth() const
	{
		return mWindow->GetWidth();
	}

	int GameWindow::GetHeight() const
	{
		return mWindow->GetHeight();
	}

}