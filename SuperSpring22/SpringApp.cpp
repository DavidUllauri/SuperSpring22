#include "SpringApp.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

SpringApp::SpringApp():
	Keys(), mTimeToApex(0.4f), mJumpHeight(4.0f)
{
	mGravity = (-2 * mJumpHeight) / (mTimeToApex * mTimeToApex);
	mJumpSpeed = (2 * mJumpHeight) / mTimeToApex;

	SetKeyPressedCallback([this](const TDE::KeyPressedEvent& e) {
		if (e.GetKeyCode() >= 0 && e.GetKeyCode() < 1024)
			Keys[e.GetKeyCode()] = true;
	});

	SetKeyReleasedCallback([this](const TDE::KeyReleasedEvent& e) {
		if (e.GetKeyCode() >= 0 && e.GetKeyCode() < 1024)
			Keys[e.GetKeyCode()] = false;
	});

	mDangers[0].SetX(600);
	mDangers[0].SetY(100);

	mStar.SetX(700);
	mStar.SetY(100);

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
	if (mGameState == GameState::ACTIVE)
	{
		int inputx = GetInputX(mPlayer); // 1 for right, -1 for left, 0 standing still
		mPlayer.SetActiveImage(inputx);
		mXVelocity = mHorizontalSpeed * inputx;
	
		if (mPlayer.collisions.below || mPlayer.collisions.above)
			mYVelocity = 0;

		if (Keys[TDE_KEY_SPACE] && mPlayer.collisions.below)
			mYVelocity = mJumpSpeed;
	
		mYVelocity += mGravity * deltaTime;
		mYVelocity = (mYVelocity < -22) ? -22 : mYVelocity;

		mPlayer.collisions.Reset();

		mPlayer.SetX(mPlayer.GetX() + mXVelocity);

		if (mPlayer.HorizontalCollisions(mDangers[0], mXVelocity))
		{
			mGameState = GameState::LOSE;
			mGameOverImage.SetY(0);
		}
		if (mPlayer.HorizontalCollisions(mStar, mXVelocity))
		{
			mGameState = GameState::WIN;
			mWinImage.SetY(0);
		}
		for (Entity& tile : gamelevel)
			if (mXVelocity != 0)
				mPlayer.HorizontalCollisions(tile, mXVelocity);
	
		mPlayer.SetY(mPlayer.GetY() + mYVelocity);

		if (mYVelocity != 0)
		{
			if (mPlayer.VerticalCollisions(mDangers[0], mYVelocity))
			{
				mGameState = GameState::LOSE;
				mGameOverImage.SetY(0);
			}
			if (mPlayer.VerticalCollisions(mStar, mYVelocity))
			{
				mGameState = GameState::WIN;
				mWinImage.SetY(0);
			}
			for (Entity& tile : gamelevel)
				mPlayer.VerticalCollisions(tile, mYVelocity);

		}

		mDangers[0].SetX(mDangers[0].GetX() - 2);

		mDangers[0].Draw();
		mStar.Draw();
		mPlayer.Draw();
		for (Entity& tile : gamelevel)
			tile.Draw();
	}
	else if (mGameState == GameState::LOSE)
	{
		mGameOverImage.Draw();
		if (Keys[TDE_KEY_ENTER, TDE_KEY_SPACE])
		{
			mPlayer.SetX(0);
			mPlayer.SetY(700);
			mPlayer.collisions.Reset();
			mDangers[0].SetX(600);
			mGameState = GameState::ACTIVE;
		}
	}
	else if (mGameState == GameState::WIN)
	{
		mWinImage.Draw();
		if (Keys[TDE_KEY_ENTER, TDE_KEY_SPACE])
		{
			mPlayer.SetX(0);
			mPlayer.SetY(700);
			mPlayer.collisions.Reset();
			mDangers[0].SetX(600);
			mGameState = GameState::ACTIVE;
		}
	}
	else
	{
		mGameState = GameState::ACTIVE;
	}
}

int SpringApp::GetInputX(Entity& gameObj)
{
	if (Keys[TDE_KEY_LEFT] && Keys[TDE_KEY_RIGHT])
	{
		return 0;
	}
	else if (Keys[TDE_KEY_LEFT])
	{
		return -1;
	}
	else if (Keys[TDE_KEY_RIGHT])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
