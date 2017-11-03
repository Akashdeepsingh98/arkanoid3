#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2 & pos_in, const Vec2 & vel_in):
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);		//The sprite codex has the ball drawing function. Only the position of ball on gfx object should be known.
}

void Ball::Update(float dt)
{
	pos += vel*dt;							//The position Vector is easily updated using the operator redefinitions in Vec2 class.
}
