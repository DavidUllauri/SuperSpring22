#include "SpringApp.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int prevX{ 0 }, prevY{ 0 };
bool colAboveBottom = { false };
int gravity = -10;

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
		case TDE_KEY_SPACE:
			mVerticalSpeed = -1;
		default:
			break;
		}
	};
	SetKeyPressedCallback(keypressedcallbackfunction);

	SetKeyReleasedCallback([this](const TDE::KeyReleasedEvent& e) {
		mHorizontalSpeed = 0;
		mVerticalSpeed = 1;
	});
	mDangers[0].SetX(400);
	mDangers[0].SetY(400);

	for (int i = 0; i < 8; i++)
	{
		Entity obj{ {"assets/img/tile.png"} };
		obj.SetX(i * 100);
		obj.SetY(0);
		gamelevel.push_back(obj);
	}
}

void SpringApp::OnUpdate()
{
	mPlayer.SetX(mPlayer.GetX() + mHorizontalSpeed);

	if (mHorizontalSpeed != 0)
		mPlayer.HorizontalCollisions(mDangers[0], mHorizontalSpeed);
	for (Entity& tile : gamelevel)
		if (mHorizontalSpeed != 0)
			mPlayer.HorizontalCollisions(tile, mHorizontalSpeed);
	
	mPlayer.SetY(mPlayer.GetY() + gravity * mVerticalSpeed);

	if (gravity != 0)
		mPlayer.VerticalCollisions(mDangers[0], gravity * mVerticalSpeed);
	for (Entity& tile : gamelevel)
		if (gravity != 0)
			mPlayer.VerticalCollisions(tile, gravity * mVerticalSpeed);

	mDangers[0].Draw();
	mPlayer.Draw();
	for (Entity& tile : gamelevel)
		tile.Draw();
}
