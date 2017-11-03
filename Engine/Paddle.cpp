#include "Paddle.h"

Paddle::Paddle(const Vec2 & pos_in, float halfwidth_in, float halfheight_in):
	pos(pos_in),
	halfwidth(halfwidth_in),
	halfheight(halfheight_in)
{
}

void Paddle::Draw(Graphics & gfx)
{
	RectF rect = GetRect();
	gfx.DrawRect(rect, wingcolor);
	rect.left += wingwidth;
	rect.right -= wingwidth;
	gfx.DrawRect(rect, color);
}

bool Paddle::DoBallCollision(Ball & ball) const
{
	if ( ball.GetVelocity().y>0 && GetRect().isOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF & walls)
{
	const RectF rect = GetRect();
	if (rect.left <= walls.left)
	{
		pos.x += walls.left - rect.left;
	}
	if (rect.right >= walls.right)
	{
		pos.x -= rect.right - walls.right;
	}
}

void Paddle::Update(const Keyboard & kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed*dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed*dt;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos,halfwidth,halfheight);
}
