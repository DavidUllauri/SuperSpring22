#include "pch.h"
#include "GameWindow.h"
#include "opengl/WinWindow.h"

namespace TDE
{
	GameWindow::GameWindow()
	{
#ifdef TDE_WINDOWS
		mWindow = new WinWindow;
#elif defined TDE_MACOS
		mWindow = new WinWindow;
#elif defined TDE_LINUX
		mWindow = new WinWindow;
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
		return mWindow->CreateWindow(width, height, windowName);
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

	void GameWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)> keyPressedCallback)
	{
		mWindow->SetKeyPressedCallback(keyPressedCallback);
	}

}