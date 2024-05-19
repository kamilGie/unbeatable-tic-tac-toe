#include "game.hpp"

Game::Game() {
    GameInit();
}

void Game::GameInit() {
    fields.assign(9, 0);
    Winner = 0;
    turn = 0;
    if (GetRandomValue(0, 1)) { computeXMove(); }
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
    if (Winner) {
        if (Winner == 1) { DrawText("O WIN", 333, 410, 80, WHITE); }
        if (Winner == 2) { DrawText("X WIN", 333, 410, 80, WHITE); }
        if (Winner == 3) { DrawText("DRAW", 333, 410, 80, WHITE); }
        DrawText("press r to reset", 318, 500, 30, WHITE);
    }
}

void Game::HandleInput() {
    if (IsKeyPressed(KEY_R)) { GameInit(); }

    if (!Winner && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        int fieldPos = GetMouseX() / 300 + GetMouseY() / 300 * 3;
        if (!fields[fieldPos]) {
            fields[fieldPos] = 1;
            turn++;
            if (isWiningMove()) {
                Winner = 1;
            } else if (turn != 9) {
                computeXMove();
            }

            if (!Winner && turn == 9) { Winner = 3; }
        }
    }
}

void Game::computeXMove() {
    turn++;
    if (turn <= 3) {
        firstMoves();
        return;
    }

    int xMove = INT_MAX;
    for (int i = 0; i < 9; i++) {
        if (!fields[i]) {
            fields[i] = 2;
            if (isWiningMove()) {
                Winner = 2;
                return;
            } else {
                fields[i] = 1;
                if (isWiningMove()) { xMove = i; }
            }
            fields[i] = 0;
        }
    }

    //there is no the best move
    if(xMove == INT_MAX){
        if (turn == 4 ) {
            firstMoves();
            return;
        }
        do {
            xMove = GetRandomValue(0, 8);
        } while (fields[xMove]);
    }

    fields[xMove] = 2;
}

void Game::firstMoves() {
    int unbeatableFirstMoves[5] = {0, 2, 4, 6, 8};
    int xMove;
    do {
        xMove = unbeatableFirstMoves[GetRandomValue(0, 5)];
    } while (fields[xMove]);
    fields[xMove] = 2;
}

bool Game::isWiningMove() {
    bool isDiagonallyWin = isWinningTriplet(fields[0], fields[4], fields[8]) || isWinningTriplet(fields[4], fields[2], fields[6]);
    bool isHorizontallyWin = isWinningTriplet(fields[0], fields[1], fields[2]) || isWinningTriplet(fields[3], fields[4], fields[5]) || isWinningTriplet(fields[6], fields[7], fields[8]);
    bool isVerticalWin = isWinningTriplet(fields[0], fields[3], fields[6]) || isWinningTriplet(fields[1], fields[4], fields[7]) || isWinningTriplet(fields[2], fields[5], fields[8]);
    return isDiagonallyWin || isHorizontallyWin || isVerticalWin;
}

bool Game::isWinningTriplet(int a, int b, int c) {
    return a != 0 && (a == b && b == c);
}