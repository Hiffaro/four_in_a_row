#include "Game.h"
#include <iostream>

Game::Game(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2)
    : mPlayer1(player1), mPlayer2(player2), mPlayfield(std::make_shared<Playfield>()) {
    mPlayer1->assignPlayfield(mPlayfield);
    mPlayer2->assignPlayfield(mPlayfield);
}

void Game::playGame() {
    while(!mPlayfield->gameOver()) {
        // Clear the screen.
        std::cout << "\033[2J" << std::flush;

        // Print the game field.
        mPlayfield->printGame();

        if(mTurn == PLAYER_ONE) {
            mPlayer1->doMove();
            mTurn = PLAYER_TWO;
        } else {
            mPlayer2->doMove();
            mTurn = PLAYER_ONE;
        }
    }
}