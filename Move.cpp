//
//  Move.cpp
//  
//
//  Created by Arthur Bacon on 11/28/16.
//
//

#include "Move.h"


using namespace endless_game;

/**
 * A constructor for a Move.
 */
Move::Move(int target, int damage, std::string message) noexcept :
target_(target), damage_(damage), message_(message) { }

/**
 * A destructor
 */
Move::~Move() noexcept { }

/**
 * A getter method that return the target of this move.
 * 1 implies the target is the player
 * -1 implies the target is the Monster
 * 0 implies the caster of the Move is defending
 */
int Move::target() const {
  return target_;
}

/**
 * A getter method that returns the damage this move deals.
 * To simulate healing, damage done should be negative.
 */
int Move::damage() const {
  return damage_;
}

/**
 * A getter method that returns the string to be printed
 * to the screen.
 */
std::string Move::message() const {
  return message_;
}






