//
//  Monster.h
//  
//
//  Created by Arthur Bacon on 11/23/16.
//
//

#ifndef Monster_h
#define Monster_h

#include "Character.h"

namespace endless_game {
  
/**
 * To represent a generic monster in the endless game.
 */
class Monster : public Character {
  
  public:
  
  /**
   * A virtual destructor.
   */
  virtual ~Monster() noexcept { }
  
  /**
   * Returns the Move that the monster will use next.
   * It may also update the monster to set up a different
   * move next time. 
   * @return a Move that the monster want's to do. 
   */
  virtual std::shared_ptr<Move> nextAttack() noexcept = 0;
};
  
}


#endif /* Monster_h */
