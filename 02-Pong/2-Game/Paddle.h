#ifndef PADDLE_H
#define PADDLE_H

#include <string>
#include <vector>
#include "Raylib.h"
#include "Actor.h"

using std::string;
using std::vector;

class Paddle : public Actor {
private:
    int speed{ 500 };
    bool isAI{ false };

public:
    void SetIsAI(bool _isAI) { isAI = _isAI; }

private:
public:
    Paddle(Vector2 _pos, Vector2 _size);
    ~Paddle();

    void Update(Vector2* scroll)override;
    void Draw(Vector2* scroll)override;
};

#endif