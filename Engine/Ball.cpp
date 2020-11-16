#include "Ball.h"

Ball::Ball()
	:
	rng(rd()),
	dist(-2.0f, 2.0f)
{
}

void Ball::Draw(Graphics& gfx)
{
	gfx.DrawRect(int(x), int(y), dimension, dimension, color);
}

void Ball::Update()
{
	x += xv * speed;
	y += yv * speed;

	ScreenYBounce();
}

bool Ball::TestPaddleCollision(Paddle paddle)
{
	const int ballLeft = int(x), ballRight = int(x + dimension);
	const int ballTop = int(y), ballBottom = int(y + dimension);
	const int paddleLeft = int(paddle.GetX()), paddleRight = int(paddle.GetX() + paddle.GetWidth());
	const int paddleTop = int(paddle.GetY()), paddleBottom = int(paddle.GetY() + paddle.GetHeight());

	return ballBottom >= paddleTop && ballTop <= paddleBottom &&
		ballRight >= paddleLeft && ballLeft <= paddleRight;
}

void Ball::PaddleCollision()
{
	xv = -xv;
	yv = dist(rng);
}

void Ball::ScreenYBounce()
{
	if (y <= 0)
	{
		y = 0;
		yv = -yv;
	}
	if (y >= Graphics::ScreenHeight - 1 - dimension)
	{
		y = Graphics::ScreenHeight - 1 - dimension;
		yv = -yv;
	}
}

void Ball::ScreenXGoal(Paddle paddleLeft, Paddle paddleRight)
{
	if (x <= 0)
	{
		x = Graphics::ScreenWidth / 2 - dimension / 2;
		y = Graphics::ScreenHeight / 2 - dimension / 2;
		xv = 1;
		yv = 0;
		paddleRight.IncrementScore();
	}
	if (x >= Graphics::ScreenWidth - 1 - dimension)
	{
		x = Graphics::ScreenWidth / 2 - dimension / 2;
		y = Graphics::ScreenHeight / 2 - dimension / 2;
		xv = -1;
		yv = 0;
		paddleLeft.IncrementScore();
	}
}
