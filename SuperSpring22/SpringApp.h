#pragma once

#include "TDE.h"
#include "Entity.h"

class SpringApp : public TDE::TDEApp
{
public:
	SpringApp();

	virtual void OnUpdate(float deltaTime) override;
	int GetInputX(Entity& gameObj);

	bool Keys[1024];
private:
	Entity mPlayer{ {"assets/img/Fin_right_100.png", "assets/img/Fin_left_100.png"} };	// Entity(right,left)
	std::vector<Entity> mDangers{ {{"assets/img/Skeleton_right.png","assets/img/Skeleton_left.png"}} };
	std::vector<Entity> gamelevel;
	int mEnemyVSpeed{ -5 };

	int mHorizontalSpeed{ 0 }; // speed measured in pixels per frame
	int mVerticalSpeed{ 0 }; // speed measured in pixels per frame
};
