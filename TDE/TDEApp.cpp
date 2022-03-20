#include "pch.h"

#include "TDEApp.h"
#include "GameWindow.h"

namespace TDE
{
	void TDEApp::Run()
	{
		TDE_LOG("TDE running...");

		TDE::GameWindow::Init();

		TDE::GameWindow::GetWindow()->CreateWindow(640, 480, "My Title");

		while (true)
		{
			OnUpdate();
			
			TDE::GameWindow::GetWindow()->SwapBuffers();
			TDE::GameWindow::GetWindow()->PollEvents();
		}
	}
	void TDEApp::OnUpdate()
	{
	}
}
