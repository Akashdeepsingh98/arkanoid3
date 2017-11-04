#pragma once
#include "RectF.h"		//Every brick is a rectangle.
#include "Colors.h"		//Every brick is colored so that we can see.
#include "Graphics.h"	//For getting the gfx object to draw on.
#include "Ball.h"
class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect_in, Color color_in);		//The constructor. No need to make color reference because it is just 3 or 4 numbers.
	void Draw(Graphics& gfx)const;						//Draw the brick on the frame. So refernce to the one and only frame is passed. Since the brick is unchanged, function ends with const.
	bool DoBallCollsion(Ball& ball);
private:
	RectF rect;
	Color color;
	bool destroyed = false;		//For knowing if a brick is destroyed or not. Default is false because when created it must be visible.
};