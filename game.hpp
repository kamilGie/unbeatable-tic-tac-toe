#pragma once
#include <raylib.h>

#include <vector>

class Game {
   public:
    Game();
    void BoardDraw();
    void GameDraw();
    void HandleInput();
    void GameInit();

   private:
    bool isWiningMove();
    bool isWinningTriplet(int a, int b, int c);
    void computeXMove();
    void firstMoves();

   private:
    std::vector<int> fields;
    int Winner;
    int turn;
};