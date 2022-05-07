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
	void TDEApp::Run()
	{
		TDE_LOG("TDE running...");

		TDE::GameWindow::Init();

		TDE::GameWindow::GetWindow()->CreateWindow(800, 600, "game window");


		Renderer::Init();

		//TDE::Sprite star{ "../TDE/assets/container.jpg" };
		TDE::Sprite star{ "../TDE/assets/img/Star_sm.png" };

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		int x{ 50 }, y{ 50 };

		auto keyPressed = [&x](const KeyPressedEvent& event) {
			TDE_LOG("Pressed: " << event.GetKeyCode()); 
			if (event.GetKeyCode() == TDE_KEY_LEFT) x -= 5;
			else if (event.GetKeyCode() == TDE_KEY_RIGHT) x += 5;
		};
		auto keyReleased = [](const KeyReleasedEvent& event) {
			TDE_LOG("Released: " << event.GetKeyCode()); 
		};
		SetKeyPressedCallback(keyPressed);
		SetKeyReleasedCallback(keyReleased);

		while (true) // !glfwWindowShouldClose(window)
		{
			OnUpdate();

			Renderer::ClearScreen();

			Renderer::Draw(star, x, y, 1);


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
