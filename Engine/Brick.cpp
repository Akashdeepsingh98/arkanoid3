#include "Brick.h"

Brick::Brick(const RectF & rect_in, Color color_in):
	rect(rect_in),
	color(color_in)
{
}

void Brick::Draw(Graphics & gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(rect.GetExpanded(-padding), color);
	}
}

bool Brick::DoBallCollsion(Ball & ball)
{
	if (!destroyed && rect.isOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}
	return false;
}
