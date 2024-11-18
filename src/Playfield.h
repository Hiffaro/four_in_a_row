#pragma once
#include <vector>
#include "Piece.h"

#define PLAYFIELD_WIDTH  7
#define PLAYFIELD_HEIGHT 6

class Playfield {
    std::vector<Piece> mPlayfield;
    Piece mWinner = Piece::EMPTY;

public:
    Playfield();

    bool dropPiece(Piece piece, int column);
    bool gameOver();
    void printGame();
    Piece getWinner();

private:
    bool checkHorizontal(int x, int y);
    bool checkVertical(int x, int y);
    bool checkDiagonal1(int x, int y);
    bool checkDiagonal2(int x, int y);
    Piece getPieceAt(int x, int y);
};