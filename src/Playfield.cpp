#include "Playfield.h"
#include <iostream>

Playfield::Playfield() {
    for(int i = 0; i < PLAYFIELD_WIDTH * PLAYFIELD_HEIGHT; ++i) {
        mPlayfield.push_back(Piece::EMPTY);
    }
}

bool Playfield::dropPiece(Piece piece, int column) {
    for(int y = PLAYFIELD_HEIGHT-1; y >= 0; --y) {
        Piece p = mPlayfield[y * PLAYFIELD_WIDTH + column];
        if(p == Piece::EMPTY) {
            mPlayfield[y * PLAYFIELD_WIDTH + column] = piece;
            return true;
        }
    }
    return false;
}

bool Playfield::gameOver() {
    // Check if the top row is full.
    bool topFull = true;
    for(int x = 0; x < PLAYFIELD_WIDTH; ++x) {
        if(getPieceAt(x, 0) == Piece::EMPTY) {
            topFull = false;
            break;
        }
    }
    if(topFull) return true;

    // No, not full, check for winner properly.
    for(int y = 0; y < PLAYFIELD_HEIGHT; ++y) {
        for(int x = 0; x < PLAYFIELD_WIDTH; ++x) {
            Piece p = getPieceAt(x, y);
            if(p != Piece::EMPTY) {
                if(checkHorizontal(x, y) || checkVertical(x, y) || checkDiagonal1(x, y) || checkDiagonal2(x, y)) {
                    mWinner = p;
                    return true;
                }
            }
        }
    }
    return false;
}

void Playfield::printGame() {
    for(int y = 0; y < PLAYFIELD_HEIGHT; ++y) {
        for(int x = 0; x < PLAYFIELD_WIDTH; ++x) {
            Piece p = getPieceAt(x, y);
            if(p == Piece::EMPTY)         std::cout << ". ";
            else if(p == Piece::PLAYER_1) std::cout << "1 ";
            else                          std::cout << "2 ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "1 2 3 4 5 6 7" << std::endl;
}

Piece Playfield::getWinner() {
    // Note, this function assumes that Playfield::gameOver has returned true.
    return mWinner;
}

bool Playfield::checkHorizontal(int x, int y) {
    Piece initial = getPieceAt(x, y);
    return (
        initial != Piece::EMPTY &&
        getPieceAt(x+1, y) == initial &&
        getPieceAt(x+2, y) == initial &&
        getPieceAt(x+3, y) == initial
    );
}

bool Playfield::checkVertical(int x, int y) {
    Piece initial = getPieceAt(x, y);
    return (
        initial != Piece::EMPTY &&
        getPieceAt(x, y+1) == initial &&
        getPieceAt(x, y+2) == initial &&
        getPieceAt(x, y+3) == initial
    );
}

bool Playfield::checkDiagonal1(int x, int y) {
    Piece initial = getPieceAt(x, y);
    return (
        initial != Piece::EMPTY &&
        getPieceAt(x+1, y+1) == initial &&
        getPieceAt(x+2, y+2) == initial &&
        getPieceAt(x+3, y+3) == initial
    );
}

bool Playfield::checkDiagonal2(int x, int y) {
    Piece initial = getPieceAt(x, y);
    return (
        initial != Piece::EMPTY &&
        getPieceAt(x-1, y+1) == initial &&
        getPieceAt(x-2, y+2) == initial &&
        getPieceAt(x-3, y+3) == initial
    );
}

Piece Playfield::getPieceAt(int x, int y) {
    if(x < 0 || x >= PLAYFIELD_WIDTH) return Piece::EMPTY;
    if(y < 0 || y >= PLAYFIELD_HEIGHT) return Piece::EMPTY;
    return mPlayfield[y * PLAYFIELD_WIDTH + x];
}
