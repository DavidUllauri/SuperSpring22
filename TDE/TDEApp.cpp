#include "pch.h"

#include "TDEApp.h"
#include "GameWindow.h"

#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"

namespace TDE
{
	TDEApp::TDEApp()
	{
		TDE::GameWindow::Init();

		TDE::GameWindow::GetWindow()->CreateWindow(800, 800, "game window");

		Renderer::Init();
	}

	void TDEApp::Run()
	{
		TDE_LOG("TDE running...");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) // !glfwWindowShouldClose(window)
		{
			Renderer::ClearScreen();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			
			TDE::GameWindow::GetWindow()->SwapBuffers();
			TDE::GameWindow::GetWindow()->PollEvents();

			mNextFrameTime += mFrameDuration;
		}
	}
	void TDEApp::OnUpdate()
	{
	}
	
	void TDEApp::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(keyPressedCallback);
	}

	void TDEApp::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(keyReleasedCallback);
	}
}
