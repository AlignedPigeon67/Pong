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
	paddleLeft(25.0f),
	paddleRight(float(gfx.ScreenWidth - 1) - paddleRight.GetWidth() - 25.0f)
{
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
	if (wnd.kbd.KeyIsPressed('W')) paddleLeft.Update('W');
	if (wnd.kbd.KeyIsPressed('S')) paddleLeft.Update('S');
	if (wnd.kbd.KeyIsPressed(VK_UP)) paddleRight.Update('W');
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) paddleRight.Update('S');

	ball.Update();

	if (ball.TestPaddleCollision(paddleLeft))
	{
		ball.PaddleCollision();
		paddleLeft.IncrementScore();
	}
	if (ball.TestPaddleCollision(paddleRight))
	{
		ball.PaddleCollision();
		paddleRight.IncrementScore();
	}

	ball.ScreenXGoal(paddleLeft, paddleRight);
}


void Game::ComposeFrame()
{
	paddleLeft.Draw(gfx);
	paddleRight.Draw(gfx);
	ball.Draw(gfx);
}
