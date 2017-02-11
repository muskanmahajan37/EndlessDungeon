//
//  Game.cpp
//  
//
//  Created by Arthur Bacon on 11/28/16.
//
//

#include "Game.h"

using namespace endless_game;

/**
 * The constructor for the main Game object.
 */
Game::Game() noexcept : player_(std::unique_ptr<Player>(new Player())),
               monster_(std::shared_ptr<Monster>(new Dragon(1))) {
  
  gameOver_ = false;
  monsterKilled_ = false;
  difficulty_ = 1;
}

/**
 * The destructor for the main game object.
 */
Game::~Game() noexcept { }

/**
 * The main logic behind running the game. 
 */
void Game::playGame() noexcept {
  monster_ = makeMonster();
  
  while(!gameOver_) {
    //While the game is NOT over
    
    ///////////////
    // Logic for user interactions
    
    //Generate a valid input
    std::string userInput;
    std::cout << "What would you like to do: ";
    std::cin >> userInput;
    
    while(!isValidMove(userInput)) {
      
      if (userInput.compare("Health") == 0) {
        std::cout << "Your health is: " << player_->getHP() << std::endl;
        std:: cout << "Monster health is: " << monster_->getHP() << std::endl;
      } else {
      
        // While the userInput string is not valid, get a new one
        std::cout << "I'm sorry I didn't understand that. " << std::endl;
        std::cout << "You may \"Attack\", \"Defend\", \"Heal\"" << std::endl;
        std::cout << "or type \"Health\" to see remaining health." << std::endl;
      
      }
      
      
      std::cout << std::endl << "What would you like to do: ";
      std::cin >> userInput;
    }
    
    //Turn input into player move
    std::shared_ptr<Move> playerMove = stringToMove(userInput);
    
    //Get monster move
    std::shared_ptr<Move> monsterMove = getMonsterMove();
    
    
    ////////////////////////////
    // Logic dealing with a block Move
    bool blocked = false;
    //If the player blocks, display monsterMove message, then display that it was blocked
    if (playerMove->target() == 0) {
      // Player is blocking
      std::cout << monsterMove->message() << "..." << std::endl;
      std::cout <<  "... But you block it!" << std::endl << std::endl;
      blocked = true;
    }
    
    //If the monster blocks, display playerMove message, then display that it was blocked
    if (monsterMove->target() == 0) {
      // Monster is blocking
      std::cout << playerMove->message() << "..." << std::endl;
      std::cout << "... But the monster blokcs it!" << std::endl;
      blocked = true;
    }
    
    
    /////////////////////////////
    // Logic for normal processing of a Move
    if (!blocked) {
      // If a move has not been blocked, process the moves as normal
      
      //do player move
      doMove(playerMove);
    
      bool isMonsterAlive = true;
      //check if monster is dead
      if (monster_->getHP() <= 0) {
        std::cout <<  "You killed the monster!" << std::endl;
        // Make a new monster and restart the loop.
        monster_ = makeMonster();
        isMonsterAlive = false;
      }
    
      if (isMonsterAlive) {
    
        //do monster move
        doMove(monsterMove);
    
        //check if player is dead
        if (player_->getHP() <= 0) {
          gameOver();
        }
      }
    }
    
  } // End of while (!gameOver) loop
}


/**
 * Checks if the given string can be converted into a Move object.
 */
bool Game::isValidMove(std::string m) const {
  if ((m.compare("Attack") == 0)
      || (m.compare("Heal") == 0)
      || (m.compare("Defend") == 0)) {
    return true;
  } else {
    return false;
  }
}

/**
 * Converts a string into a Move object.
 */
std::shared_ptr<Move> Game::stringToMove(std::string userInput) const {
  
  if ((userInput.compare("Attack")) == 0) {
    return player_->attack();
    
  } else if ((userInput.compare("Defend")) == 0) {
    return player_->defend();
    
  } else if ((userInput.compare("Heal")) == 0) {
    return player_->heal();
    
  } else {
    throw std::invalid_argument("Cannot convert string to move");
  }
  
}

/**
 * Creates a new monster, random species and scaled damage.
 */
std::shared_ptr<Monster> Game::makeMonster() noexcept {
  
  srand (time(NULL));
  
  int iSecret = rand() % 3;
  
  
  if (iSecret == 0) {
    std::cout << std::endl << "You find a lonely goblin." << std::endl;
    return std::shared_ptr<Monster> (new Goblin(difficulty_));
  } else if (iSecret == 1) {
    std::cout << std::endl << "The trees come to life! An ent!" << std::endl;
    return std::shared_ptr<Monster> (new Ent(difficulty_));
  } else {
    // (iSecrete == 2)
    std::cout << std::endl << "A dragon challenges you. Prepare yourself!" << std::endl;
    return std::shared_ptr<Monster> (new Dragon(difficulty_));
  }
  
  difficulty_ = difficulty_ + 1;
}

/**
 * A process that ends the game.
 */
void Game::gameOver() noexcept {
  gameOver_ = true;
  std::cout << "Game over" << std::endl;
}

/**
 * Generates the net move the monster wants to make.
 */
std::shared_ptr<Move> Game::getMonsterMove() const {
  return (*monster_).nextAttack();
}

/**
 * Logic for processing a single move.
 */
void Game::doMove(std::shared_ptr<Move> m) noexcept {
  
  if (gameOver_ || monsterKilled_) {
    monsterKilled_ = false;
    return;
  }
  
  // Apply the damage to the target, then display the message
  if (m->target() == 1) {
    // target is Player
    doMoveOnPlayer(m);
  } else if (m->target() == 0) {
    //
  } else if (m->target() == -1) {
    // Target is the monster
    doMoveOnMonster(m);
  } else {
    throw std::domain_error("Move target is not a supported number");
  }
}

/**
 * Applies the given move on the player.
 */
void Game::doMoveOnPlayer(std::shared_ptr<Move> m) noexcept {
  
  std::cout << m->message() << std::endl;
  
  
  if (!player_->damage(m->damage())) {
    // By calling m.damage we already have hit the player's hp
    // If we are in here the player's hp is <= 0
  }
  
}

/**
 * Applies the given move on the monster. 
 */
void Game::doMoveOnMonster(std::shared_ptr<Move> m)  noexcept {
  
  std::cout << m->message() << std::endl;
  
  
  if (monster_->damage(m->damage())) {
    // By calling m.damage we already have hit the monster's hp
    // If we are in here the monster's hp is <= 0
    // Build a new monster.
    
    std::cout << "You killed the monster!" << std::endl;
    
    monster_ = makeMonster();
    monsterKilled_ = true;
  }
  
}







