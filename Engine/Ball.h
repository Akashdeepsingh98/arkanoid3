#pragma once
#include "Vec2.h"
#include "Graphics.h"
class Ball
{
public:
	Ball(const Vec2& pos_in, const Vec2& vel_in);		//Get the beginning position and velocity of ball.
	void Draw(Graphics& gfx)const;						//Though the ball is moving, in each frame the ball is basically drawn anew. So drawing keeps the ball's members constant.
	void Update(float dt);								//dt is the time step to update the ball's position and velocity. Since members are being changed, no const qualifier at end.
private:
	static constexpr float radius = 7.0f;		//The radius of ball should be known at compile time and it will never change.
	Vec2 pos;									//Track the position of ball on-screen.
	Vec2 vel;									//Track the velocity of ball because it moves unlike the bricks.
};