#include "Paddle.h"

Paddle::Paddle(Vector2 _pos, Vector2 _size):
	Actor(_pos, _size, ActorType::UI, AssetList::GetTexture("Button"))
{
	SetHasCollision(true);
	SetEnabled(true);
}

Paddle::~Paddle() {
}

void Paddle::Update(Vector2* scroll) {
	int inputs = 0;
	if (isAI) {
		Vector2 ballPos = GetActorWithName("Ball")->GetPosition();
		if (ballPos.y > position.y + size.y * 0.25f) inputs++;
		if (ballPos.y < position.y - size.y * 0.25f) inputs--;
	}
	else {
		inputs -= IsKeyDown(KEY_UP);
		inputs += IsKeyDown(KEY_DOWN);
	}
	position.y += inputs * speed * GetFrameTime();
}

void Paddle::Draw(Vector2* scroll) {
	Rectangle source{ 0, 0, texture->width, texture->height };
	Rectangle dest{ position.x, position.y, size.x, size.y };
	DrawTexturePro(*texture, source, dest, Vector2{ size.x * 0.5f, size.y * 0.5f }, 0, color);
}