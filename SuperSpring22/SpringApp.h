#pragma once

#include "TDE.h"
#include "Entity.h"

class SpringApp : public TDE::TDEApp
{
public:
	SpringApp();

	virtual void OnUpdate(float deltaTime) override;
	int GetInputX(Entity& gameObj);

	bool Keys[349];
private:
	Entity mPlayer{ {"assets/img/Fin_right_100.png", "assets/img/Fin_left_100.png"} };	// Entity(right,left)
	std::vector<Entity> mDangers{ {{"assets/img/Skeleton_right.png","assets/img/Skeleton_left.png"}} };
	std::vector<Entity> gamelevel;
	int mEnemyVSpeed{ -5 };

	int mHorizontalSpeed{ 5 }; // speed measured in pixels per frame
	float mJumpSpeed{ 0 };
	float mTimeToApex; // Time player takes to reach Apex of jump
	float mJumpHeight; // Desired jump height
	float mXVelocity{ 0 };
	float mYVelocity{ 0 };
	float mGravity{ 0 };
};
