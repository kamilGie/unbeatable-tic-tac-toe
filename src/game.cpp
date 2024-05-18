#include "game.hpp"

Game::Game() {
    fields.assign(9, 0);
}

void Game::BoardDraw() {
    DrawLineEx({300, 0}, {300, 900}, 10, WHITE);
    DrawLineEx({600, 0}, {600, 900}, 10, WHITE);
    DrawLineEx({0, 300}, {900, 300}, 10, WHITE);
    DrawLineEx({0, 600}, {900, 600}, 10, WHITE);
}

void Game::GameDraw() {
    for (int i = 0; i < 9; i++) {
        if (fields[i] == 1) {
            float x = i % 3 * 300 + 150;
            float y = i / 3 * 300 + 150;
            DrawRing({x, y}, 130, 110, 0, 360, 36, BLUE);
        }

        if (fields[i] == 2) {
            float x = i % 3 * 300 +25;
            float y = i / 3 * 300 +25;
            DrawLineEx({x,y},{x+250,y+250},20,RED);
            DrawLineEx({x+250,y},{x,y+250},20,RED);
        }
    }
}

void Game::HandleInput() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        int x = GetMouseX() / 300;
        int y = GetMouseY() / 300;
        fields[x + y * 3] = 1;
    }
    //test only
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        int x = GetMouseX() / 300;
        int y = GetMouseY() / 300;
        fields[x + y * 3] = 2;
    }
}

void Game::Update() {
}
