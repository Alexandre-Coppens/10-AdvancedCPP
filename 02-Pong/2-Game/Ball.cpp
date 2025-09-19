#include "Ball.h"

Ball::Ball(Vector2 _pos, Vector2 _size): 
	Actor(_pos, _size)
{
	direction = Vector2{ (float)GetRandomValue(-5, 5), 0.5f * GetRandomValue(-1, 1)};
}

Ball::~Ball() {
}

void Ball::Update(Vector2* scroll) {
	if (position.x + size.x > GetScreenWidth() || position.x < 0) direction.x *= -1;
	if (position.y + size.y > GetScreenHeight() || position.y < 0) direction.y *= -1;
	direction = Vector2Normalize(direction);
	position = Vector2Add(position, Vector2Scale(direction, speed * GetFrameTime()));
}

void Ball::Draw(Vector2* scroll) {
	DrawCircle(position.x, position.y, size.x * 0.5f, BLUE);
}