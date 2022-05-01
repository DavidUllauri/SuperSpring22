#include "pch.h"

#include "TDEApp.h"
#include "GameWindow.h"

#include "Sprite.h"
#include "Renderer.h"

namespace TDE
{
	void TDEApp::Run()
	{
		TDE_LOG("TDE running...");

		TDE::GameWindow::Init();

		TDE::GameWindow::GetWindow()->CreateWindow(800, 600, "game window");


		Renderer::Init();

		//TDE::Sprite star{ "../TDE/assets/container.jpg" };
		TDE::Sprite star{ "../TDE/assets/img/Star.png" };

		int xPos{ -star.GetWidth() };

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)
		{
			OnUpdate();

			Renderer::ClearScreen();

			Renderer::Draw(star, xPos, 20, 1);

			xPos = (xPos + 5);

			std::this_thread::sleep_until(mNextFrameTime);
			
			TDE::GameWindow::GetWindow()->SwapBuffers();
			TDE::GameWindow::GetWindow()->PollEvents();

			mNextFrameTime += mFrameDuration;
		}
	}
	void TDEApp::OnUpdate()
	{
	}
}
