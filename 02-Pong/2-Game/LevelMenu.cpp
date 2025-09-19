#include "LevelMenu.h"

#include "Button.h"

LevelMenu::LevelMenu(string _name):Level(_name){
}

LevelMenu::~LevelMenu(){
}

void LevelMenu::Start() {
	AddNewActorToList(Actor::CreateActor("Button", 0, new Button(Vector2{GetScreenWidth() * 0.5f, GetScreenHeight() * 0.8f}, Vector2{ 300, 100})));
}