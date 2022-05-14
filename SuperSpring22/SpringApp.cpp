#include "SpringApp.h"

void SpringApp::OnUpdate()
{
	switch (mPlayerState)
	{
	case SpringApp::PlayerStates::Standing:
		break;
	case SpringApp::PlayerStates::Running:
		break;
	case SpringApp::PlayerStates::Jumping:
		break;
	default:
		break;
	}
}

bool SpringApp::CollideX(const Entity& one, const Entity& two)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int twoLeft{ two.GetX() };
	int twoRight{ two.GetX() + two.GetWidth() };

	if ((twoLeft <= oneLeft and oneLeft <= twoRight) or
		(twoLeft <= oneRight and oneRight <= twoRight) or
		(oneLeft <= twoRight and twoLeft <= oneRight))
		return true;
	else
		return false;
}

bool SpringApp::CollideY(const Entity& one, const Entity& two)
{
	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int twoBottom{ two.GetY() };
	int twoTop{ two.GetY() + two.GetHeight() };

	if ((twoBottom <= oneBottom and oneBottom <= twoTop) or
		(twoBottom <= oneTop and oneTop <= twoTop) or
		(oneBottom <= twoTop and twoBottom <= oneTop))
		return true;
	else
		return false;
}
