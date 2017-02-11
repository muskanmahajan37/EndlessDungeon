//
//  Move.h
//  
//
//  Created by Arthur Bacon on 11/28/16.
//
//

#ifndef Move_hpp
#define Move_hpp

#include <stdio.h>
#include <string>

namespace endless_game {
  
/**
 * A class to represent a generic Move in an RPG game. Every
 * move contains a target, the amout of damage delt and a 
 * message to be displayed to the screen.
 */
class Move {

  public:
  
  /**
   * A constructor for a Move.
   * for the target param:
   * 1 implies the target is the player
   * -1 implies the target is the Monster
   * 0 implies the caster of the Move is defending
   */
  Move(// The target of this move
       int target,
       // The damage this move will deal to the target
       int damage,
       // The message to be displayed along with the move
       std::string message) noexcept;
  
  /**
   * A destructor.
   */
  ~Move() noexcept;
  
  /**
   * A getter method that return the target of this move.
   * 1 implies the target is the player
   * -1 implies the target is the Monster
   * 0 implies the caster of the Move is defending
   *
   * @return the value of this Move's target
   */
  int target() const;
  
  /**
   * A getter method that returns the damage this move deals.
   * To simulate healing, damage done should be negative.
   *
   * @return the value of this Move's damage
   */
  int damage() const;
  
  /**
   * A getter method that returns the string to be printed 
   * to the screen.
   *
   * @return the message that goes with this Move.
   */
  std::string message() const;
  
  private:
  /**
   * The target of this Move. 
   * 1 => target is the Player
   * -1 => target is the Monster
   * 0 => caster is attempting to defend
   */
  const int target_;
  // The damage this Move deals to the target.
  const int damage_;
  // The message this Move displays to the screen. 
  const std::string message_;
  
};
}

#endif /* Move_hpp */
