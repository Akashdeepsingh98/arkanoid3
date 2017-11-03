#pragma once
#include "Vec2.h"					//The primary reason of inclusion is for 3rd and 4th constructors
class RectF							//Since Arkanoid needs a lot of Rectangles, so we feed the idea of what a rectangle IS by making a class for rectangles specially, just like vectors.
{
public:

	//CONSTRUCTORS ONLY BLOCK
	RectF(float left_in, float right_in, float top_in, float bottom_in);						//This constructor disables the default constructor of compiler
	RectF() = default;																			//So here the compiler is told to used the default constructor as well when necessary
	//The following constructors take Vectors. Only reference because passing by value is heavy, and making them "const" ensures they can't be tampered with.
	RectF(const Vec2& top_left, const Vec2& bottom_right);										//This constructor can take top-left and bottom-right coordinates of rectangle
	RectF(const Vec2& top_left, float width, float height);										//Take only top-left coordiante and the width and height of rectangles
	//CONSTRUCTORS BLOCK ENDS

	//FUNCTIONS BLOCK START
	bool isOverlappingWith(const RectF& other)const;		//The current rectangle is tested for collision with another rectangle of smae class. Nothing should be tampered with hence "const"
	//FUNCTIONS BLOCK ENDS
public:
	float left;							//represents left of rectangle
	float right;						//represents right of rectangle
	float top;							//represents top of rectangle
	float bottom;						//represents top of rectangle
};