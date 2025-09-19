#include "LevelGame.h"

#include "Ball.h"
#include "Paddle.h"

LevelGame::LevelGame(string _name) :Level(_name) {
}

LevelGame::~LevelGame() {
}

void LevelGame::Start() {
	AddNewActorToList(Actor::CreateActor("Ball", 0, new Ball(Vector2{ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f }, Vector2{ 20, 20 })));
	AddNewActorToList(Actor::CreateActor("Paddle", 0, new Paddle(Vector2{ 20.0f, GetScreenHeight() * 0.5f }, Vector2{ 20, 100 })));
	AddNewActorToList(Actor::CreateActor("PaddleAI", 0, new Paddle(Vector2{ GetScreenWidth() - 20.0f, GetScreenHeight() * 0.5f }, Vector2{ 20, 100 })));

	static_cast<Paddle*>(Actor::GetActorWithName("PaddleAI"))->SetIsAI(true);
}