#include "Button.h"
#include "Levels.h"

Button::Button(Vector2 _pos, Vector2 _size) :
	Actor(_pos, _size, ActorType::UI, AssetList::GetTexture("Button"))
{
}

Button::~Button() {
}

void Button::Update(Vector2* scroll) {
	if (IsMouseButtonPressed(0)) {
		if (GetMousePosition().x > position.x - size.x * 0.5f &&
			GetMousePosition().x < position.x + size.x * 0.5f &&
			GetMousePosition().y > position.y - size.y * 0.5f &&
			GetMousePosition().y < position.y + size.y * 0.5f) {
			Level::LevelList[Level::currentLevel]->LoadLevelbyID(1);
		}
	}
}

void Button::Draw(Vector2* scroll) {
	Rectangle source{ 0, 0, texture->width, texture->height };
	Rectangle dest{ position.x, position.y, size.x, size.y };
	DrawTexturePro(*texture, source, dest, Vector2{ size.x * 0.5f, size.y * 0.5f }, 0, color);
}