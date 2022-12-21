#include "GamePiece.hpp"
#include "GameState.hpp"
#include <iostream>
#include <string>
using std::string;

GamePiece::GamePiece(
    string const& play, string const& piece,
    GameState* state) {  // Constructor to build a piece when given 3 arguments
  player = play;
  play_piece = piece;
  currGame = state;

  currGame->AddPiece(player, play_piece);
}

GamePiece::~GamePiece() {  // Destructor to remove a GamePiece from GameState
  currGame->KillPiece(player, play_piece);
}

GamePiece::GamePiece(GamePiece const& s) {  // Constructor called whenever a
                                            // copy of a GamePiece is made
  player = s.player;
  play_piece = s.play_piece;
  currGame = s.currGame;

  currGame->AddPiece(player, play_piece);
}

string GamePiece::GetPlayer() {  // Returns the name of the player that owns the
                                 // GamePiece
  return player;
}

string GamePiece::GetType() {  // Returns the type of character the GamePiece is
  return play_piece;
}

int GamePiece::GetPower()
    const {  // Returns the Power that the GamePiece posseses
  if (play_piece == "Wizard") {
    int wizards = currGame->NumPieces(player, play_piece);
    return wizards;
  } else if (play_piece == "Warrior") {
    return 5;
  } else {
    return 1;
  }
}

int GamePiece::GetSpeed()
    const {  // Returns the Speed that the GamePiece is able to travel
  if (play_piece == "Wizard") {
    int speed = 12 - currGame->WizardCount(player);
    if (speed < 1) {
      speed = 1;
    }
    return speed;
  } else if (play_piece == "Warrior") {
    return 2;
  } else {
    return 8;
  }
}

bool GamePiece::operator<(const GamePiece& rhs)
    const {  // Overloads the '<' operator so two GamePieces can be compared
  if (this->GetPower() < rhs.GetPower()) {
    return true;
  } else if (this->GetPower() == rhs.GetPower()) {
    if (this->GetSpeed() < rhs.GetSpeed()) {
      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }
}

bool GamePiece::operator>(const GamePiece& rhs)
    const {  // Overloads the '>' operator so two GamePieces can be compared
  if (this->GetPower() > rhs.GetPower()) {
    return true;
  } else if (this->GetPower() == rhs.GetPower()) {
    if (this->GetSpeed() > rhs.GetSpeed()) {
      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }
}

bool GamePiece::operator<=(const GamePiece& rhs)
    const {  // Overloads the '<=' operator so two GamePieces can be compared
  if (this->GetPower() < rhs.GetPower()) {
    return true;
  } else if (this->GetPower() == rhs.GetPower()) {
    if (this->GetSpeed() <= rhs.GetSpeed()) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool GamePiece::operator>=(const GamePiece& rhs)
    const {  // Overloads the '>=' operator so two GamePieces can be compared
  if (this->GetPower() > rhs.GetPower()) {
    return true;
  } else if (this->GetPower() == rhs.GetPower()) {
    if (this->GetSpeed() >= rhs.GetSpeed()) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool GamePiece::operator!=(const GamePiece& rhs)
    const {  // Overloads the '!=' operator so two GamePieces can be compared
  if (*this > rhs) {
    return true;
  } else if (*this < rhs) {
    return true;
  } else {
    return false;
  }
}

bool GamePiece::operator==(const GamePiece& obj)
    const {  // Overloads the '==' operator so two GamePieces can be compared
  if (this->GetPower() == obj.GetPower() &&
      this->GetSpeed() == obj.GetSpeed()) {
    return true;
  } else {
    return false;
  }
}

GamePiece& GamePiece::operator=(GamePiece obj) {  // Overloads the assignment
                                                  // operator so one GamePieces
                                                  // can become another existing
                                                  // one.
  currGame->KillPiece(player, play_piece);
  player = obj.player;
  play_piece = obj.play_piece;
  currGame = obj.currGame;
  currGame->AddPiece(player, play_piece);
  return *this;
}

ostream& operator<<(ostream& oss,
                    GamePiece const& obj) {  // Overloads the '<<' operator so
                                             // GamePieces can be output via
                                             // ostreams
  oss << "(" << obj.player << "," << obj.play_piece << "," << obj.GetPower()
      << "," << obj.GetSpeed() << ")";
  return oss;
}
