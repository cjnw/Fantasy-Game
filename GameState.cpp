#include "GameState.hpp"
#include <string>
using std::string;

void GameState::AddPiece(
    string const& person,
    string const& figure) {  // Appends a new GamePiece to its respective map
  if (figure == "Warrior") {
    Warriors[person]++;
  } else if (figure == "Wizard") {
    ++Wizards[person];
  } else {
    Scouts[person]++;
  }
}

int GameState::NumPieces() {  // Returns the total number of pieces in play in
                              // the game
  int sum = 0;
  for (auto i : Warriors) {
    sum += i.second;
  }
  for (auto j : Wizards) {
    sum += j.second;
  }
  for (auto k : Scouts) {
    sum += k.second;
  }
  return sum;
}

int GameState::NumPieces(string const& player_name) {  // Returns the total
                                                       // number of pieces a
                                                       // player owns in the
                                                       // game
  return Warriors[player_name] + Wizards[player_name] + Scouts[player_name];
}

int GameState::NumPieces(string const& player_name,
                         string const& piece_type) {  // Returns the number of
                                                      // pieces a player owns
                                                      // that is of a specified
                                                      // type
  if (piece_type == "Warrior") {
    return Warriors[player_name];
  } else if (piece_type == "Wizard") {
    return Wizards[player_name];
  } else if (piece_type == "Scout") {
    return Scouts[player_name];
  } else {
    return 0;
  }
}

int GameState::WizardCount(
    string const& player) {  // Returns the total number of Wizards in play, not
                             // including the amount owned by a specified player
  int WizCo = 0;  // Wizard Count
  for (auto i : Wizards) {
    if (i.first == player) {
      continue;
    }
    WizCo += i.second;
  }
  return WizCo;
}

void GameState::KillPiece(string const& person,
                          string const& figure) {  // Removes a piece from its
                                                   // respective owner by
                                                   // decrementing its map value
  if (figure == "Warrior") {
    Warriors[person]--;
  } else if (figure == "Wizard") {
    Wizards[person]--;
  } else {
    Scouts[person]--;
  }
}
