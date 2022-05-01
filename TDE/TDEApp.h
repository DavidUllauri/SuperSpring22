#pragma once

#include "Core.h"
#include "pch.h"

#define AIR_FRAMERATE 60

namespace TDE 
{
	class TDE_API TDEApp
	{
	public:
		void Run();
		virtual void OnUpdate();
	
	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / AIR_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
