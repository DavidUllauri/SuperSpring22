#include "SpringApp.h"

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
		default:
			break;
		}
	};
	SetKeyPressedCallback(keypressedcallbackfunction);

	SetKeyReleasedCallback([this](const TDE::KeyReleasedEvent& e) {
		mHorizontalSpeed = 0;
	});
	mDangers[0].SetX(400);
	mDangers[0].SetY(400);
}

void SpringApp::OnUpdate()
{
	mPlayer.SetX(mPlayer.GetX() + mHorizontalSpeed);

	if (mDangers[0].GetY() < 0)
		mEnemyVSpeed *= -1;
	else if (mDangers[0].GetY() > TDE::GameWindow::GetWindow()->GetHeight() - mDangers[0].GetHeight())
		mEnemyVSpeed *= -1;

	mDangers[0].SetY(mDangers[0].GetY() + mEnemyVSpeed);

	if (Collide(mPlayer, mDangers[0]))
	{
		exit(0);
	}

	mDangers[0].Draw();
	mPlayer.Draw();
}

bool SpringApp::Collide(const Entity& one, const Entity& two)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int twoLeft{ two.GetX() };
	int twoRight{ two.GetX() + two.GetWidth() };

	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int twoBottom{ two.GetY() };
	int twoTop{ two.GetY() + two.GetHeight() };

	bool collideX{ false };
	if ((oneLeft <= twoLeft and twoLeft <= oneRight) or
		(twoLeft <= oneLeft and oneLeft <= twoRight))
		collideX = true;

	bool collideY{ false };
	if ((oneBottom <= twoBottom and twoBottom <= oneTop) or
		(twoBottom <= oneBottom and oneBottom <= twoTop))
		collideY = true;

	return collideX and collideY;
}
