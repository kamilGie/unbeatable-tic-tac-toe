#include <raylib.h>

#include <iostream>

#include "game.hpp"
using namespace std;

int main() {
    const int screenWidth = 900;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "tic tac toe");
    SetTargetFPS(120);

    Game game;
    while (!WindowShouldClose()) {
        game.HandleInput();

        BeginDrawing();
        ClearBackground(BLACK);
        game.BoardDraw();
        game.GameDraw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}