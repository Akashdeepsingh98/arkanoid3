#pragma once
#include "Ball.h"
#include "Graphics.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Keyboard.h"
class Paddle
{
public:
	Paddle(const Vec2& pos_in, float halfwidth_in, float halfheight_in);
	void Draw(Graphics& gfx);
	bool DoBallCollision(Ball& ball)const;
	void DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect()const;
private:
	static constexpr float wingwidth = 18.0f;
	Color wingcolor = Colors::Red;
	Color color = Colors::White;
	float speed = 300.0f;
	float halfwidth;
	float halfheight;
	Vec2 pos;
};