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
		float lastFrame{ 0.0f }, deltaTime{ 0.0f };

		while (!WindowShouldClose()) 
		{
			float currentFrame = GameWindow::GetWindow()->GetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			Renderer::ClearScreen();

			OnUpdate(deltaTime);

			std::this_thread::sleep_until(mNextFrameTime);
			
			TDE::GameWindow::GetWindow()->SwapBuffers();
			TDE::GameWindow::GetWindow()->PollEvents();

			mNextFrameTime += mFrameDuration;
		}
	}
	void TDEApp::OnUpdate(float deltaTime)
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
	bool TDEApp::WindowShouldClose()
	{
		return GameWindow::GetWindow()->WindowShouldClose();
	}
}
