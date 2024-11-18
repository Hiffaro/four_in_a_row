#pragma once
#include "Player.h"
#include "Playfield.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(Piece playerId);
    virtual void doMove() override;
};