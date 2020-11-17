#include "Paddle.h"
#include "Graphics.h"

Paddle::Paddle(float xPosition)
	:
	x(xPosition)
{
}

float Paddle::GetWidth() const
{
	return width;
}

float Paddle::GetHeight() const
{
	return height;
}

int Paddle::GetScore() const
{
	return score;
}

void Paddle::IncrementScore()
{
	++score;
}

void Paddle::ScreenYBorder()
{
	if (y <= 0) y = 0;
	if (y >= Graphics::ScreenHeight - 1 - height) y = Graphics::ScreenHeight - 1 - height;
}

void Paddle::Draw(Graphics& gfx) const
{
	gfx.DrawRect(int(x), int(y), width, height, color);
}

void Paddle::Update(char key, float dt)
{
	if (key == 'W') y -= speed * dt;
	else if (key == 'S') y += speed * dt;

	ScreenYBorder();
}

float Paddle::GetX() const
{
	return x;
}

float Paddle::GetY() const
{
	return y;
}

