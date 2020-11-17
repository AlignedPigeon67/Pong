#pragma once

#include "Graphics.h"

class Paddle
{
public:
	Paddle(float xPosition);
	void Draw(Graphics& gfx) const;
	void Update(char key, float dt);
	float GetX() const;
	float GetY() const;
	float GetWidth() const;
	float GetHeight() const;
	int GetScore() const;
	void IncrementScore();
private:
	void ScreenYBorder();
	float x;
	float y = Graphics::ScreenHeight / 2 - height / 2;
	static constexpr int width = 10;
	static constexpr int height = 50;
	static constexpr float speed = 4.0f * 60.0f;
	int score = 0;
	Color color = Colors::White;
};

