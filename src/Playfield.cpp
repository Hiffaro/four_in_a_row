#include "Playfield.h"
#include <iostream>

Playfield::Playfield() {
    for(int i = 0; i < PLAYFIELD_WIDTH * PLAYFIELD_HEIGHT; ++i) {
        mPlayfield.push_back(Piece::EMPTY);
    }
}

bool Playfield::gameOver() {
    return false;
}

void Playfield::printGame() {
    for(int y = 0; y < PLAYFIELD_HEIGHT; ++y) {
        for(int x = 0; x < PLAYFIELD_WIDTH; ++x) {
            Piece p = mPlayfield[y * PLAYFIELD_WIDTH + x];
            if(p == Piece::EMPTY)         std::cout << ". ";
            else if(p == Piece::PLAYER_1) std::cout << "1 ";
            else                          std::cout << "2 ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "1 2 3 4 5 6 7" << std::endl;
}
