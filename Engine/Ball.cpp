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

bool Ball::DoWallCollision(const RectF & walls)
{
	bool collided = false;					//Initialy assumed ball isn't colliding.
	const RectF rect = GetRect();
	if (rect.left <= walls.left)
	{
		pos.x += walls.left - rect.left;	//first bring the ball's position within walls because the loop will update ball to out of bounds.
		ReboundX();							//Then rebound the velocity
		collided = true;
	}
	if (rect.right >= walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
		collided = true;
	}
	if (rect.top <= walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collided = true;
	}
	if (rect.bottom >= walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		collided = true;
	}
	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos,radius,radius);
}

Vec2 Ball::GetVelocity()
{
	return vel;
}
