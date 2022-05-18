#pragma once

#include "TDE.h"
#include "Entity.h"

class SpringApp : public TDE::TDEApp
{
public:
	SpringApp();

	virtual void OnUpdate() override;

	bool Collide(const Entity& one, const Entity& two);
private:
	Entity mPlayer{ {"assets/img/Fin_right_100.png", "assets/img/Fin_left_100.png"} };	// Entity(right,left)
	std::vector<Entity> mDangers{ {{"assets/img/Skeleton_right.png","assets/img/Skeleton_left.png"}} };
	int mEnemyVSpeed{ -5 };

	int mHorizontalSpeed{ 0 }; // speed measured in pixels per frame
};
