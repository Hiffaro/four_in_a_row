#pragma once
#include <memory>
#include "Playfield.h"

class Player {
protected:
    std::shared_ptr<Playfield> mPlayfield;
    Piece mPlayerId;

public:
    Player(Piece playerId);
    void assignPlayfield(std::shared_ptr<Playfield> playfield);
    virtual void doMove() = 0;
};