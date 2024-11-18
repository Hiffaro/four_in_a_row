#include <iostream>
#include <memory>
#include "HumanPlayer.h"
#include "Game.h"

int main(int argc, char **argv) {
    auto player1 = std::make_shared<HumanPlayer>(Piece::PLAYER_1);
    auto player2 = std::make_shared<HumanPlayer>(Piece::PLAYER_2);

    Game game(player1, player2);
    game.playGame();

    return 0;
}