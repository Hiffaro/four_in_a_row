#include "Player.h"

Player::Player(Piece playerId) : mPlayerId(playerId) {}

void Player::assignPlayfield(std::shared_ptr<Playfield> playfield) {
    mPlayfield = playfield;
}
