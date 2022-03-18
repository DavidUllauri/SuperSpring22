#include "pch.h"

#include "TDEApp.h"

namespace TDE
{
	void TDEApp::Run()
	{
		TDE_LOG("TDE running...\n");
		while (true)
		{
			OnUpdate();
		}
	}
	void TDEApp::OnUpdate()
	{
	}
}
