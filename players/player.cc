#include "player.h"
#include "playerImpl.h"

Player::Player(Colour colour, PlayerImpl * behaviour): colour{colour}, check{false}, checkmate{false}, behaviour{behaviour}, wins{0} {}

void Player::setBehaviour(PlayerImpl * behaviour) {
    this->behaviour = behaviour;
}

Move Player::chooseMove(Move* lastMove) {
    behaviour->setColour(colour);
    return behaviour->chooseMove(lastMove);
}

