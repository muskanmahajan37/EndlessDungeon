//
//  Player.hpp
//  
//
//  Created by Arthur Bacon on 11/27/16.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <string>
#include "Character.h"


namespace endless_game {
  
/**
 * A class to represent the player character, or the Character
 * that the user will controle.
 */
class Player : public Character {

  
  public:
  
  /**
   * A constructor that takes user input to make this 
   * Character's name.
   */
  Player() noexcept;
  
  /**
   * A destructor for a player. 
   */
  ~Player() noexcept;
  
  /**
   * Returns the current HP of this character.
   * @return the current HP of this character.
   */
  int getHP() const;
  
  /**
   * Returns the name of this character.
   * @return the name of this character.
   */
  std::string getName() const;
  
  /**
   * returns true if the Character is above 0 hp after the 
   * damage is delt. 
   * @return true if this character has died by applying the damage.
   */
  bool damage(// The amount of damage to be delt to this character.
              int damage) noexcept;
  
  /**
   * A Move that heals this character.
   * @return a move that will heal this character.
   */
  std::shared_ptr<Move> heal() noexcept;
  
  /**
   * A move that attaks the oposing monster.
   * @return a Move that will attack the monster.
   */
  std::shared_ptr<Move> attack() noexcept;
  
  /**
   * A move that blocks all incoming damage. 
   * @return a Move that will block this character from damage. 
   */
  std::shared_ptr<Move> defend() noexcept;
  
  
  protected:
  
  
  private:
  /**
   * A variable to represent the name of this Character.
   */
  std::string name_;
  
  /**
   * A variable to represent the current health of this 
   * character. 
   */
  int hp_;

};
  
}


#endif /* Player_hpp */
