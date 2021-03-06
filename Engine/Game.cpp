/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(300.0f,300.0f),Vec2(100.0f,100.0f)),
	walls(0.0f,float(gfx.ScreenWidth),0.0f,float(gfx.ScreenHeight)),
	soundpad(L"Sounds\\arkpad.wav"),
	soundbrick(L"Sounds\\arkbrick.wav"),
	pad(Vec2(500.0f,500.0f),40.0f,20.0f)
{
	const Color colors[4] = { Colors::Red,Colors::Blue,Colors::Green,Colors::Cyan };
	const Vec2 topleft(0.0f, 0.0f);
	int i = 0;
	for (int y = 0; y < nBricksDown; y++)
	{
		for (int x = 0; x < nBricksAcross; x++)
		{
			bricks[i] = Brick(RectF(topleft + Vec2(x*brickWidth, y*brickHeight), brickWidth, brickHeight), colors[y]);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	
	const float dt = ft.Mark();
	pad.Update(wnd.kbd, dt);
	pad.DoWallCollision(walls);
	ball.Update(dt);
	for (Brick& b : bricks)
	{
		if (b.DoBallCollsion(ball))
		{
			soundbrick.Play();
			break;
		}
	}
	if (pad.DoBallCollision(ball))
	{
		soundpad.Play();
	}
	if (ball.DoWallCollision(walls))
	{
		soundpad.Play();
	}
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	for (const Brick& b : bricks)			//Range based for loop
	{
		b.Draw(gfx);
	}
	pad.Draw(gfx);
}
