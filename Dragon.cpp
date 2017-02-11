//
//  Dragon.cpp
//  
//
//  Created by Arthur Bacon on 11/28/16.
//
//

#include "Dragon.h"
#include <iostream>
#include <math.h>

using namespace endless_game;

/**
 * A simple constructor.
 */
Dragon::Dragon(int difficulty) noexcept : Monster() {
  difficulty_ = difficulty;
  
  health_ = 20 + (difficulty * 5);
  
  nextFire_ = false;
}

/**
 * A destructor.
 */
Dragon::~Dragon() noexcept { }

/**
 * Returns the current health.
 */
int Dragon::getHP() const {
  return health_;
}

/**
 * Returns the name.
 */
std::string Dragon::getName() const {
  return "Dragon";
}

/**
 * Returns true if the dragon is dead.
 */
bool Dragon::damage(int damage) noexcept {
  health_ = health_ - damage;
  return health_ <= 0;
}

/**
 * Returns the Move the monster is going to use for their
 * next attack. This method also will update and return a
 * different move next time it is called.
 */
std::shared_ptr<Move> Dragon::nextAttack() noexcept {
  srand (time(NULL));
  
  int rInt = rand() % 3;
  
  if (nextFire_) {
    nextFire_ = false;
    return std::shared_ptr<Move> (new Move(1, 50 * floor(difficulty_ / 4) , "The dragon breathes fire on you!"));
  }
  
  if (rInt == 0) {
    nextFire_ = true;
    return std::shared_ptr<Move> (new Move(1, 0, "The dragon prepares to breath fire..."));
  } else if (rInt == 1) {
    return std::shared_ptr<Move> (new Move(1, 10 + (difficulty_ * 2), "The dragon lashes out with it's claws."));
  } else {
    //(rInt == 2)
    return std::shared_ptr<Move> (new Move(-1, 0, "The dragon flies high into the sky."));
  }
}

