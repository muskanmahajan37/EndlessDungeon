//
//  Goblin.cpp
//  
//
//  Created by Arthur Bacon on 12/4/16.
//
//

#include "Goblin.h"


using namespace endless_game;


/**
 * A simple constructor.
 */
Goblin::Goblin(int difficulty) noexcept : Monster() {
  difficulty_ = difficulty;
  health_ = 5 + (difficulty * 2);
}

/**
 * A destructor
 */
Goblin::~Goblin() noexcept { }

/**
 * Returns the current health of this monster.
 */
int Goblin::getHP() const {
  return health_;
}

/**
 * retunrs the name of this monster.
 */
std::string Goblin::getName() const {
  return "Goblin";
}

/**
 * Returns true if the monster is dead
 */
bool Goblin::damage(int damage) noexcept {
  health_ = health_ - damage;
  return health_ <= 0;
}

/**
 * Returns the Move the monster is going to use for their
 * next attac. This method also will update and return a
 * different move next time it is called.
 */
std::shared_ptr<Move> Goblin::nextAttack() noexcept {
  srand (time(NULL));
  
  int iSecret = rand() % 3;
  
  
  if (iSecret == 0) {
    return std::shared_ptr<Move> (new Move(-1, 0, "The goblin trips and falls. Clumsy creature."));
  } else if (iSecret == 1) {
    return std::shared_ptr<Move> (new Move(1, 3 + (difficulty_ * 3), "The goblin stabs with it's sword."));
  } else {
    //(iSecret == 2)
    return std::shared_ptr<Move> (new Move(1, 6 * floor(difficulty_ / 5), "The goblin jumps forward, slashing wildly."));
  }
}


