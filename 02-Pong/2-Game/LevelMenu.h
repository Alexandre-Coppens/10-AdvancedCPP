#ifndef LEVELMENU_H
#define LEVELMENU_H

#include <string>
#include <vector>
#include <map>
#include "Raylib.h"
#include "Levels.h"

using std::string;
using std::vector;
using std::map;

class LevelMenu : public Level {
private:
public:

private:
public:
    LevelMenu(string _name);
    ~LevelMenu();

    void Start() override;
};

#endif