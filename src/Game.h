#pragma once
#include <memory>
#include "Player.h"
#include "Playfield.h"

#define PLAYER_ONE 0
#define PLAYER_TWO 1

class Game {
    std::shared_ptr<Player> mPlayer1;
    std::shared_ptr<Player> mPlayer2;
    std::shared_ptr<Playfield> mPlayfield;
    int mTurn = PLAYER_ONE;

public:
    Game(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
    void playGame();
};