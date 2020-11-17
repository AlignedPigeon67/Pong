#pragma once

#include <random>
#include "Graphics.h"
#include "Paddle.h"


class Ball
{
public:
	Ball();
	void Draw(Graphics& gfx);
	void Update(float dt);
	void TestPaddleCollision(Paddle paddle);
	void ScreenXGoal(Paddle paddleLeft, Paddle paddleRight);
private:
	void ScreenYBounce();
	float x = Graphics::ScreenWidth / 2 - dimension / 2;
	float y = Graphics::ScreenHeight / 2 - dimension / 2;
	float xv = -1.0f;
	float yv = -1.0f;
	static constexpr int dimension = 10;
	float speed = 4.0f * 60.0f;
	Color color = Colors::White;

	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> dist;
};

