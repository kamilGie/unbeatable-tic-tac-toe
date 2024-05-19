#include "raylib.h"
#include "game.hpp"

int main() {
    const int screenWidth = 900;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "TICTACTOE");
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
}