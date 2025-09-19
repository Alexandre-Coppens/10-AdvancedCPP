#ifndef BALL_H
#define BALL_H

#include <string>
#include <vector>
#include "Raylib.h"
#include "Actor.h"

using std::string;
using std::vector;
using std::map;

class Ball : public Actor {
private:
    int speed{ 500 };
    Vector2 direction{};
public:

private:
public:
    Ball(Vector2 _pos, Vector2 _size);
    ~Ball();

    void Update(Vector2* scroll)override;
    void Draw(Vector2* scroll)override;
};

#endif