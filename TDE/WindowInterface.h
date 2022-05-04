#pragma once
#include "pch.h"
#include "Events.h"

namespace TDE
{
	class WindowInterface
	{
	public:
		virtual bool CreateWindow(int width, int height, const std::string& windowName) = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)> keyPressedCallback) = 0;
	};
}
