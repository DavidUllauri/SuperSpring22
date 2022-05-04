#pragma once

#include "Core.h"
#include "pch.h"
#include "Events.h"
#define AIR_FRAMERATE 60

namespace TDE 
{
	class TDE_API TDEApp
	{
	public:
		void Run();
		virtual void OnUpdate();
		virtual void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / AIR_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
