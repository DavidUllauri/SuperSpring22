#include "SpringApp.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

int prevX{ 0 }, prevY{ 0 };
bool colAboveBottom = { false };

SpringApp::SpringApp():
	Keys(), mTimeToApex(0.4f), mJumpHeight(4.0f)
{
	mGravity = (-2 * mJumpHeight) / (mTimeToApex * mTimeToApex);
	mJumpSpeed = (2 * mJumpHeight) / mTimeToApex;

	SetKeyPressedCallback([this](const TDE::KeyPressedEvent& e) {
		if (e.GetKeyCode() >= 0 and e.GetKeyCode() < 1024)
			Keys[e.GetKeyCode()] = true;
	});

	SetKeyReleasedCallback([this](const TDE::KeyReleasedEvent& e) {
		if (e.GetKeyCode() >= 0 and e.GetKeyCode() < 1024)
			Keys[e.GetKeyCode()] = false;
	});

	mDangers[0].SetX(400);
	mDangers[0].SetY(400);

	for (int i = 0; i < 8; i++) // Game Map
	{
		Entity obj{ {"assets/img/tile.png"} };
		obj.SetX(i * 100);
		obj.SetY(0);
		gamelevel.push_back(obj);
	}
}

void SpringApp::OnUpdate(float deltaTime)
{
	int inputx = GetInputX(mPlayer); // 1 for right, -1 for left, 0 standing still
	mXVelocity = mHorizontalSpeed * inputx;
	
	if (mPlayer.collisions.below or mPlayer.collisions.above)
		mYVelocity = 0;

	if (Keys[TDE_KEY_SPACE] and mPlayer.collisions.below)
		mYVelocity = mJumpSpeed;
	
	mYVelocity += mGravity * deltaTime;
	mYVelocity = (mYVelocity < -22) ? -22 : mYVelocity;

	mPlayer.collisions.Reset();

	mPlayer.SetX(mPlayer.GetX() + mXVelocity);

	if (mXVelocity != 0)
		mPlayer.HorizontalCollisions(mDangers[0], mXVelocity);
	for (Entity& tile : gamelevel)
		if (mXVelocity != 0)
			mPlayer.HorizontalCollisions(tile, mXVelocity);
	
	mPlayer.SetY(mPlayer.GetY() + mYVelocity);

	if (mGravity != 0)
		mPlayer.VerticalCollisions(mDangers[0], mYVelocity);
	for (Entity& tile : gamelevel)
		if (mGravity != 0)
			mPlayer.VerticalCollisions(tile, mYVelocity);

	mDangers[0].Draw();
	mPlayer.Draw();
	for (Entity& tile : gamelevel)
		tile.Draw();
}

int SpringApp::GetInputX(Entity& gameObj)
{
	if (Keys[TDE_KEY_LEFT] and Keys[TDE_KEY_RIGHT])
	{
		return 0;
	}
	else if (Keys[TDE_KEY_LEFT])
	{
		gameObj.SetActiveImage(1);
		return -1;
	}
	else if (Keys[TDE_KEY_RIGHT])
	{
		gameObj.SetActiveImage(0);
		return 1;
	}
	else
	{
		return 0;
	}
}
