//
//  Dragon.hpp
//  
//
//  Created by Arthur Bacon on 11/28/16.
//
//

#ifndef Dragon_hpp
#define Dragon_hpp

#include "Monster.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>

namespace endless_game {

/**
 * A class to represent a specific Monster, a dragon.
 */
class Dragon : public Monster {
  
  public:
  
  /**
   * A simple constructor.
   */
  Dragon(int difficulty) noexcept;
  
  /**
   * A destructor
   */
  ~Dragon() noexcept;
  
  /**
   * Returns the current health of this monster.
   * @return the current health of this monster. 
   */
  int getHP() const;
  
  
  /**
    * Damage this monster by the given amount
    * @return true if the monster is dead
    */
  bool damage(// The amount of damage to be delt to this monster
              int damage) noexcept;
  
  /**
   * Retunrs the name of this monster.
   * @return the name of this monster.
   */
  std::string getName() const;
  
  /**
   * Returns the Move the monster is going to use for their 
   * next attac. This method also will update and return a 
   * different move next time it is called.
   * @return a Move that the monster want's to do.
   */
  std::shared_ptr<Move> nextAttack() noexcept;

  
  
  private:
  // The difficulty of this monster
  int difficulty_;
  
  // The current health of this monster
  int health_;
  
  // Is the next attack going to be a major hit?
  bool nextFire_;
  
};
}

#endif /* Dragon_hpp */
