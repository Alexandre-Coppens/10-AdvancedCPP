#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <vector>
#include "Raylib.h"
#include "Actor.h"

using std::string;
using std::vector;
using std::map;

class Button : public Actor {
private:
public:

private:
public:
    Button(Vector2 _pos, Vector2 _size);
    ~Button();

    void Update(Vector2* scroll)override;
    void Draw(Vector2* scroll)override;
};

#endif