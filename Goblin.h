//
//  Goblin.hpp
//  
//
//  Created by Arthur Bacon on 12/4/16.
//
//

#ifndef Goblin_hpp
#define Goblin_hpp


#include "Monster.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>

namespace endless_game {
  
  /**
   * A class to represent a specific Monster, a dragon.
   */
class Goblin : public Monster {
    
  public:
    
    /**
     * A simple constructor.
     */
    Goblin(int difficulty) noexcept;
    
    /**
     * A destructor.
     */
    ~Goblin() noexcept;
    
    /**
     * Returns the current health of this monster.
     * @return the current health of this monster. 
     */
    int getHP() const;
    
    /**
     * Damage this monster by the given amount.
     * @return true if the monster is dead
     */
    bool damage(// The amount of damage to be delt to this monster
                int damage) noexcept;
    
    /**
     * retunrs the name of this monster.
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
    // The current difficulty of this monster
    int difficulty_;
  
    // The current health of this monster. 
    int health_;
    
    
};
}

#endif /* Goblin_hpp */
