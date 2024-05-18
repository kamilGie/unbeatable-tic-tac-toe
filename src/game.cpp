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
            float x = i % 3 * 300 + 25;
            float y = i / 3 * 300 + 25;
            DrawLineEx({x, y}, {x + 250, y + 250}, 20, RED);
            DrawLineEx({x + 250, y}, {x, y + 250}, 20, RED);
        }
    }
}

void Game::HandleInput() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        int fieldPos = GetMouseX() / 300 + GetMouseY() / 300 * 3;
        if (!fields[fieldPos]) {
            fields[fieldPos] = 1;
            if (isWiningMove(fieldPos)) {
                std::cout << "o won" << std::endl;
                fields.assign(9, 0);
            }
        }
    }

    // test only
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        int fieldPos = GetMouseX() / 300 + GetMouseY() / 300 * 3;
        if (!fields[fieldPos]) {
            fields[fieldPos] = 2;
            if (isWiningMove(fieldPos)) {
                std::cout << "X won" << std::endl;
                fields.assign(9, 0);
            }
        }
    }
}

void Game::Update() {
}

bool Game::isWiningMove(int fieldPos) {
    bool isDiagonallyWin = false;
    bool isHorizontallyWin = false;
    bool isVerticalWin = false;
    return isDiagonallyWin || isHorizontallyWin || isVerticalWin;
}
