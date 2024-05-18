#pragma once 
#include <raylib.h>
#include <vector>

class Game {
    public:
     Game();
     void BoardDraw();
     void GameDraw();
     void HandleInput();
     void Update();
    private:
    std::vector<int> fields;
    
};