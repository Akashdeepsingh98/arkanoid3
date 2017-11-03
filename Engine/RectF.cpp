#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in):
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2 & top_left, const Vec2 & bottom_right):
	RectF(top_left.x,bottom_right.x,top_left.y,bottom_right.y)					//The constructor just wrap around the 1st one
{
}

RectF::RectF(const Vec2 & top_left, float width, float height):
	RectF(top_left,top_left+Vec2(width,height))									//The constructor wraps around second one which in turn wraps around first
{
}

RectF RectF::FromCenter(const Vec2 & center, float HalfWidth, float HalfHeight)
{
	const Vec2 half(HalfWidth, HalfHeight);
	return RectF(center-half,center+half);
}

bool RectF::isOverlappingWith(const RectF & other) const
{
	return right > other.left && left < other.right &&
		bottom > other.top && top < other.bottom;
}
