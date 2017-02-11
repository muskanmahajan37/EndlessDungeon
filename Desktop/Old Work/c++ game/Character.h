//
//  CharacterBase.h
//  
//
//  Created by Arthur Bacon on 11/23/16.
//
//

#ifndef Character_h
#define Character_h

#include <string>
#include "Move.h"
#include <iostream>
#include <memory>


namespace endless_game {
  

/**
 * A class to represent a character for the endless game.
 * It can either be a player character or a monster character.
 */
class Character {

public:
  
  /**
   * A virtual destructor.
   */
  virtual ~Character() noexcept { }
  
  /**
   * Returns the current hit points for the character
   *
   * @return the value of this monster's health
   */
  virtual int getHP() const = 0;
  
  /**
   * Returns the name of the character
   *
   * @return the name of this monster.
   */
  virtual std::string getName() const = 0;
  
  /**
   * Damage this monster by the given amount
   * @return true if the monster is dead
   */
  virtual bool damage(// The amount of damage to be delt to this Character
                      int damage) noexcept = 0;
  
};
}


#endif /* Character_h */
