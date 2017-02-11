//
//  Game.hpp
//  
//
//  Created by Arthur Bacon on 11/28/16.
//
//

#ifndef Game_hpp
#define Game_hpp


#include <string>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "Dragon.h"
#include "Ent.h"
#include "Goblin.h"

#include "Move.h"

namespace endless_game {
  
/**
 * A class to represent the logic and flow of a RPG game.
 */
class Game {

  public:
  
  /**
   * A constructor that builds a Character and a starting 
   * default monster.
   */
  Game() noexcept;
  
  /**
   * A destructor for this game class. 
   */
  ~Game() noexcept;
  
  /**
   *
   */
  void playGame() noexcept;
  
  /**
   * Gets a console input from the user.
   * @return the direct quote that the user inputed into the console.
   */
  std::string getInput() const;
  
  /**
   * Process all the logic for a single turn. Asks the user and monster for an input, 
   * then translates that into a Move. Then applies the moves.
   */
  void processTurn() noexcept;
  
  /**
   * Check's to see if the provided string is a known command.
   * @return true if the provided string is a known command.
   */
  bool isValidMove(// The user's input command to see if it is well formed and recgonised.
                   std::string m) const;
  
  /**
   * Converts a valid move string (provided by the user) into a Move.
   * @return A ptr to a Move object that the Player Character will use on their turn.
   */
  std::shared_ptr<Move> stringToMove(// The user's input command to be converted into a Move.
                                     std::string userInput) const;
  
  /**
   * Creates a random Monster for the user's Player to fight next.
   * @return A new Monster type for the computer actor to controle.
   */
  std::shared_ptr<Monster> makeMonster() noexcept;
  
  /**
   * Starts the clean up process for ending the game.
   */
  void gameOver() noexcept;
  
  /**
   * Prompts the monster to pick a move action it want's to preform.
   * @return The Move object the monster wants to do on their turn.
   */
  std::shared_ptr<Move> getMonsterMove() const;
  
  /**
   * Applies the given move to the apporprate target.
   */
  void doMove(// The move to be applied.
              std::shared_ptr<Move> m) noexcept;
  
  /**
   * Applies the given move to the Player Character.
   */
  void doMoveOnPlayer(//
                      std::shared_ptr<Move> m) noexcept;
  
  /**
   * Applies the given move to the Monster Character.
   */
  void doMoveOnMonster(// The move to be applied.
                       std::shared_ptr<Move> m) noexcept;
  
  protected:
  
  
  
  private:
  // The human actor's Character.
  std::unique_ptr<Player> player_;
  // The Monster the player will fight aginst.
  std::shared_ptr<Monster> monster_;
  // Is the game over?
  bool gameOver_;
  // Is the monster dead?
  bool monsterKilled_;
  // What is the current difficulty of the game?
  int difficulty_;
  
};
}

#endif /* Game_hpp */
