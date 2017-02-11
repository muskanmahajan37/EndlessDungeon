//
//  Ent.cpp
//  
//
//  Created by Arthur Bacon on 12/4/16.
//
//

#include "Ent.h"

using namespace endless_game;


/**
 * A simple constructor.
 */
Ent::Ent(int difficulty) noexcept : Monster()  {
  difficulty_ = difficulty;
  
  nextHit_ = false;
  
  health_ = 30 * (floor(difficulty / 3) + 1);
  
}

/**
 * A destructor
 */
Ent::~Ent() noexcept { }

/**
 * Returns the current health of this monster.
 */
int Ent::getHP() const {
  return health_;
}

/**
 * Returns the name of this monster.
 */
std::string Ent::getName() const {
  return "Ent";
}

/**
 * Returns true if the monster is dead.
 */
bool Ent::damage(int damage) noexcept {
  health_ = health_ - damage;
  return health_ <= 0;
}

/**
 * Returns the Move the monster is going to use for their
 * next attack. This method also will update and return a
 * different move next time it is called.
 */
std::shared_ptr<Move> Ent::nextAttack() noexcept {
  srand (time(NULL));
  
  int rInt = rand() % 3;
  
  
  if (nextHit_) {
    nextHit_ = false;
    return std::shared_ptr<Move> (new Move(1, 15 + floor(difficulty_ / 4), "The ent smacks you with it's trunk!"));
  }
  
  if (rInt == 0) {
    int healingFactor;
    if (maxHealth_ < health_ + (4 + floor(difficulty_ / 3))) {
      // If we're trying to heal more than the max health
      healingFactor = health_ - maxHealth_;
    } else {
      healingFactor = 4 + floor(difficulty_ / 3);
    }
    
    return std::shared_ptr<Move> (new Move(-1, (-1 * healingFactor), "Ent roots itself, regenerating health."));
  } else if (rInt == 1) {
    return std::shared_ptr<Move> (new Move(1, 6 + (difficulty_ * 2), "The ent throws rasor sharp leaves at you."));
  } else {
    //(rInt == 2)
    nextHit_ = true;
    return std::shared_ptr<Move> (new Move(-1, 0, "The ent begins a wind up for a major hit..."));
  }
}








