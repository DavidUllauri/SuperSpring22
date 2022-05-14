#pragma once

#include "TDE.h"
#include "Entity.h"

class SpringApp : public TDE::TDEApp
{
public:
	virtual void OnUpdate() override;

	bool CollideX(const Entity& one, const Entity& two);
	bool CollideY(const Entity& one, const Entity& two);
private:
	Entity mPlayer{ {"assets/img/Star.png", "assets/img/Star.png"} };	// Entity(right,left)
	std::vector<Entity> Map;

	enum class PlayerStates { Standing, Running, Jumping } mPlayerState{PlayerStates::Standing};
	enum class PlayerDirection { Left, Right } mPlayerDirection{PlayerDirection::Right};

	int mHorizontalSpeed{ 0 }; // speed measured in pixels per frame
	int mVerticalSpeed{ 0 };
};
