#include "TDEApp.h"

namespace TDE
{
	void TDEApp::Run()
	{
		while (true)
		{
			OnUpdate();
		}
	}
	void TDEApp::OnUpdate()
	{
	}
}
