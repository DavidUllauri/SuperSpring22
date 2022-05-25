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

	mDanger.SetX(700);
	mDanger.SetY(100);

	mStar.SetX(900);
	mStar.SetY(100);

	gamelevel.LoadMapData("assets/levels/one.txt");
	gamelevel.CreateMap();
}

void SpringApp::OnUpdate(float deltaTime)
{
	if (mGameState != GameState::ACTIVE)
	{
		// If gamestate is not active don't move the player or check for collisions
		Render();
		return;
	}

	int inputx = GetInputX(mPlayer); // 1 for right, -1 for left, 0 standing still

	mPlayer.TurnSprite(inputx);
	mDanger.Move(mEnemyVSpeed, deltaTime);

	mXVelocity = mHorizontalSpeed * inputx;
	
	if (mPlayer.collisions.below || mPlayer.collisions.above)
		mYVelocity = 0;

	if (Keys[TDE_KEY_SPACE] && mPlayer.collisions.below)
		mYVelocity = mJumpSpeed;
	
	mYVelocity += mGravity * deltaTime;
	mYVelocity = (mYVelocity < -22) ? -22 : mYVelocity;

	mPlayer.collisions.Reset();

	mPlayer.SetX(mPlayer.GetX() + mXVelocity);

	DoXCollisions();
	
	mPlayer.SetY(mPlayer.GetY() + mYVelocity);

	if (mYVelocity != 0)
	{
		DoYCollisions();
	}

	Render();
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

void SpringApp::Render()
{
	if (mGameState == GameState::ACTIVE)
	{
		mDanger.Draw();
		mStar.Draw();
		mPlayer.Draw();
		gamelevel.Draw();
	}
	else if (mGameState == GameState::LOSE)
	{
		mGameOverImage.Draw();
		if (Keys[TDE_KEY_ENTER, TDE_KEY_SPACE])
		{
			ResetGame();
			mGameState = GameState::ACTIVE;
		}
	}
	else if (mGameState == GameState::WIN)
	{
		mWinImage.Draw();
		if (Keys[TDE_KEY_ENTER, TDE_KEY_SPACE])
		{
			ResetGame();
			mGameState = GameState::ACTIVE;
		}
	}
	else
	{
		mGameState = GameState::ACTIVE;
	}
}

void SpringApp::ResetGame()
{
	mPlayer.ResetPlayer();
	mDanger.ResetEnemy();
}

void SpringApp::DoXCollisions()
{
	if (mPlayer.HorizontalCollisions(mDanger, mXVelocity))
	{
		mGameState = GameState::LOSE;
		mGameOverImage.SetY(0);
	}
	if (mPlayer.HorizontalCollisions(mStar, mXVelocity))
	{
		mGameState = GameState::WIN;
		mWinImage.SetY(0);
	}
	for (Entity& tile : gamelevel.mMap)
		if (mXVelocity != 0)
			mPlayer.HorizontalCollisions(tile, mXVelocity);
}

void SpringApp::DoYCollisions()
{
	if (mPlayer.VerticalCollisions(mDanger, mYVelocity))
	{
		mGameState = GameState::LOSE;
		mGameOverImage.SetY(0);
	}
	if (mPlayer.VerticalCollisions(mStar, mYVelocity))
	{
		mGameState = GameState::WIN;
		mWinImage.SetY(0);
	}
	for (Entity& tile : gamelevel.mMap)
		mPlayer.VerticalCollisions(tile, mYVelocity);
}
