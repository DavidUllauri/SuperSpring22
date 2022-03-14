#pragma once

#include "TDEUtil.h"

namespace TDE 
{
	class TDE_API TDEApp
	{
	public:
		void Run();
		virtual void OnUpdate();
	};
}
