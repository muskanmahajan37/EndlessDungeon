//
//  Player.cpp
//  
//
//  Created by Arthur Bacon on 11/27/16.
//
//

#include "Player.h"
#include <iostream>


using namespace endless_game;

/**
 * A constructor that takes user input to make this
 * Character's name.
 */
Player::Player() noexcept : Character() {
  std::string name;
  std::cout << "Please input a name for your character." << std::endl;
  std::cout << "Do not use any white space characters." << std::endl;
  
  std::cin >> name;
  
  name_ = name;
  hp_ = 100;
  
}

Player::~Player() noexcept { }

/**
 * Returns the current HP of this character.
 */
int Player::getHP() const {
  return hp_;
}


bool Player::damage(int damage) noexcept {
  hp_ = hp_ - damage;
  return (hp_ > 0);
}

/**
 * Returns the name of this character.
 */
std::string Player::getName() const {
  return name_;
}

/**
 * A Move that heals this character.
 */
std::shared_ptr<Move> Player::heal() noexcept {
  std::shared_ptr<Move> result(new Move(-1, -15, "You heal yourself."));
  return result;
}

/**
 * A move that attaks the oposing monster.
 */
std::shared_ptr<Move> Player::attack() noexcept {
  std::shared_ptr<Move> result(new Move(-1, 15, "You attack the monster."));
  return result;
}

/**
 * A move that blocks all incoming damage.
 */
std::shared_ptr<Move> Player::defend() noexcept {
  // Defending is tricky. The logic for it is found
  // in the Game class, target is 0 => defence move.
  // All other Move parameters are dummies.
  std::string message = name_;
  message.append(" is trying to defend");
  
  std::shared_ptr<Move> result(new Move(0, 10, message));
  return result;
}






