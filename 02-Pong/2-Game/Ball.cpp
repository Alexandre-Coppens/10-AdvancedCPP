#include "Ball.h"
#include "Paddle.h"

Ball::Ball(Vector2 _pos, Vector2 _size): 
	Actor(_pos, _size)
{
	direction = Vector2{ (float)GetRandomValue(-99999, 99999), 0.5f * GetRandomValue(-1, 1)};
	 SetHasCollision(true);
	 SetEnabled(true);
}

Ball::~Ball() {
}

void Ball::Update(Vector2* scroll) {
	if (position.x + size.x > GetScreenWidth() || position.x < 0) direction.x *= -1;
	if (position.y + size.y > GetScreenHeight() || position.y < 0) direction.y *= -1;

	for (auto go : ActorList) {
		if (go.second != this && go.second->GetEnabled() && go.second->GetHasCollision()) {
			if (position.x < go.second->GetPosition().x + go.second->GetSize().x &&
				position.x + size.x > go.second->GetPosition().x &&
				position.y < go.second->GetPosition().y + go.second->GetSize().y &&
				position.y + size.y > go.second->GetPosition().y)
			{
				if (dynamic_cast<Paddle*>(go.second)) {
					direction.y += (((position.y + (size.y * 0.5f)) - go.second->GetPosition().y) / go.second->GetSize().y - 0.5f) * 2;
					direction = Vector2Normalize(direction);
					direction.y = Clamp(direction.y, -0.33f, 0.33f);
					direction = Vector2Normalize(direction);
				}
				float xstart = std::max(position.x, go.second->GetPosition().x);
				float xend = std::min(position.x + size.x, go.second->GetPosition().x + go.second->GetSize().x);
				float ystart = std::max(position.y, go.second->GetPosition().y);
				float yend = std::min(position.y + size.y, go.second->GetPosition().y + go.second->GetSize().y);
				if (xend - xstart > yend - ystart) {
					direction.y *= -1;
					position.y += direction.y * GetFrameTime();
				}
				else {
					direction.x *= -1;
					position.x += direction.x * GetFrameTime();
				}
				speed += 400;
				go.second->Collided();
			}
		}
	}

	speed = Lerp(speed, minSpeed, 5 * GetFrameTime());
	direction = Vector2Normalize(direction);
	position = Vector2Add(position, Vector2Scale(direction, speed * GetFrameTime()));
}

void Ball::Draw(Vector2* scroll) {
	DrawCircle(position.x, position.y, size.x * 0.5f, BLUE);
}