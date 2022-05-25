#pragma once

#include "TDE.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "GameMap.h"

class SpringApp : public TDE::TDEApp
{
public:
	SpringApp();

	virtual void OnUpdate(float deltaTime) override;
	int GetInputX(Entity& gameObj);
	void Render();
	void ResetGame();
	void DoXCollisions();
	void DoYCollisions();

	bool Keys[349];
private:
	// Hero
	Player mPlayer{ {
			"assets/img/Fin_right_100.png", 
			"assets/img/Fin_left_100.png",
			"assets/img/Fin_up_r_100.png",
			"assets/img/Fin_up_l_100.png"
	} };
	Entity mGameOverImage{ {"assets/img/game_over.png"} };
	Entity mWinImage{ {"assets/img/win_screen.png"} };
	Entity mStar{ {"assets/img/Star_sm.png"} };
	Enemy mDanger{ {"assets/img/Skeleton_right.png","assets/img/Skeleton_left.png"} };
	GameMap gamelevel;
	
	enum class GameState { ACTIVE, WIN, LOSE } mGameState{ GameState::ACTIVE };
	
	int mEnemyVSpeed{ -4 };

	int mHorizontalSpeed{ 5 }; // speed measured in pixels per frame
	float mJumpSpeed{ 0 }; // (2 * mJumpHeight) / mTimeToApex
	float mTimeToApex; // Time player takes to reach Apex of jump
	float mJumpHeight; // Desired jump height
	float mXVelocity{ 0 }; // Velocity in the x-axis
	float mYVelocity{ 0 }; // Velocity in the y-axis
	float mGravity{ 0 }; // (-2 * mJumpHeight) / mTimeToApex^2
};
