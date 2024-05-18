#pragma once 
#include <raylib.h>
#include <vector>
#include <iostream>

class Game {
    public:
     Game();
     void BoardDraw();
     void GameDraw();
     void HandleInput();
     void Update();
    private:
    std::vector<int> fields;
    bool isWiningMove(int fieldPos);
    
};