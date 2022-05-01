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
		TDE::Sprite star{"../TDE/assets/img/Star.png"};

		while (true)
		{
			OnUpdate();

			Renderer::ClearScreen();

			Renderer::Draw(star, 50, 20, 1);

			
			TDE::GameWindow::GetWindow()->SwapBuffers();
			TDE::GameWindow::GetWindow()->PollEvents();
		}
	}
	void TDEApp::OnUpdate()
	{
	}
}
