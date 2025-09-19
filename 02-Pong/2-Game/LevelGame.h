#ifndef LEVELGAME_H
#define LEVELGAME_H

#include <string>
#include <vector>
#include <map>
#include "Raylib.h"
#include "Levels.h"

using std::string;
using std::vector;
using std::map;

class LevelGame : public Level {
private:
public:

private:
public:
    LevelGame(string _name);
    ~LevelGame();

    void Start() override;
};

#endif