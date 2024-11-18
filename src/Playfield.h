#pragma once
#include <vector>
#include "Piece.h"

#define PLAYFIELD_WIDTH  7
#define PLAYFIELD_HEIGHT 6

class Playfield {
    std::vector<Piece> mPlayfield;

public:
    Playfield();

    bool gameOver();
    void printGame();
};