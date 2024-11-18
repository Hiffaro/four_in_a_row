#include "HumanPlayer.h"
#include <iostream>
#include <string>

HumanPlayer::HumanPlayer(Piece playerId) : Player(playerId) {}

void HumanPlayer::doMove() {
    std::cout << "You are player " << (mPlayerId == Piece::PLAYER_1 ? "1" : "2") << "." << std::endl;

    bool madeMove = false;
    while(!madeMove) {
        std::cout << "Drop your piece in which column? (1-7)> " << std::flush;

        std::string response;
        std::getline(std::cin, response);

        if(response.size() > 0) {
            char c = response[0];
            if(c >= '1' && c <= '7') {
                madeMove = mPlayfield->dropPiece(mPlayerId, c - '1');
            }
        }
    }
}
