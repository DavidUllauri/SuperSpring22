#include "SpringApp.h"
#include <iostream>

int prevX{ 0 }, prevY{ 0 };
bool colAboveBottom = { false };

SpringApp::SpringApp()
{
	auto keypressedcallbackfunction = [this](const TDE::KeyPressedEvent& e) {
		switch (e.GetKeyCode())
		{
		case TDE_KEY_LEFT:
			mHorizontalSpeed = -5;
			mPlayer.SetActiveImage(1);
			break;
		case TDE_KEY_RIGHT:
			mHorizontalSpeed = 5;
			mPlayer.SetActiveImage(0);
			break;
		case TDE_KEY_UP:
			mVerticalSpeed = 5;
			break;
		case TDE_KEY_DOWN:
			mVerticalSpeed = -5;
			break;
		default:
			break;
		}
	};
	SetKeyPressedCallback(keypressedcallbackfunction);

	SetKeyReleasedCallback([this](const TDE::KeyReleasedEvent& e) {
		mHorizontalSpeed = 0;
		mVerticalSpeed = 0;
	});
	mDangers[0].SetX(400);
	mDangers[0].SetY(400);
}

void SpringApp::OnUpdate()
{
	mPlayer.SetX(mPlayer.GetX() + mHorizontalSpeed);

	if (mHorizontalSpeed != 0)
		mPlayer.HorizontalCollisions(mDangers[0], mHorizontalSpeed);
	
	mPlayer.SetY(mPlayer.GetY() + mVerticalSpeed);

	if (mVerticalSpeed != 0)
		mPlayer.VerticalCollisions(mDangers[0], mVerticalSpeed);


	mDangers[0].Draw();
	mPlayer.Draw();
}
