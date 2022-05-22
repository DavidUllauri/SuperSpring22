#include "SpringApp.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

int prevX{ 0 }, prevY{ 0 };
bool colAboveBottom = { false };
float gravity{ -20 };
float yVelocity{ 0 };

SpringApp::SpringApp()
	: Keys()
{
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

	for (int i = 0; i < 8; i++)
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
	mHorizontalSpeed = 5 * inputx;
	
	if (mPlayer.collisions.below or mPlayer.collisions.above)
		yVelocity = 0;

	if (Keys[TDE_KEY_SPACE] and mPlayer.collisions.below)
		yVelocity = 13;
	
	yVelocity += gravity * deltaTime;

	mPlayer.collisions.Reset();

	mPlayer.SetX(mPlayer.GetX() + mHorizontalSpeed);

	if (mHorizontalSpeed != 0)
		mPlayer.HorizontalCollisions(mDangers[0], mHorizontalSpeed);
	for (Entity& tile : gamelevel)
		if (mHorizontalSpeed != 0)
			mPlayer.HorizontalCollisions(tile, mHorizontalSpeed);
	
	mPlayer.SetY(mPlayer.GetY() + yVelocity);

	if (gravity != 0)
		mPlayer.VerticalCollisions(mDangers[0], yVelocity);
	for (Entity& tile : gamelevel)
		if (gravity != 0)
			mPlayer.VerticalCollisions(tile, yVelocity);

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
