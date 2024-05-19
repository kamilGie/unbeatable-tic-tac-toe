#pragma once
#include <raylib.h>

#include <iostream>
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
    bool isWiningMove();
    bool isWinningTriplet(int a, int b, int c);
    void  computeXMove();
    
   private:
    int Winner;
};