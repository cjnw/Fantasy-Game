#pragma once
#include <string>
#include <map>
#include <utility>
using std::map;
using std::pair;
using std::string;

class GameState {
  map<string, int> Warriors;
  map<string, int> Scouts;
  map<string, int> Wizards;

 public:
  GameState() = default;
  void AddPiece(string const &player_name, string const &piece_type);
  void KillPiece(string const &player_name, string const &piece_type);
  int WizardCount(string const &player);
  int NumPieces();
  int NumPieces(string const &player_name);
  int NumPieces(string const &player_name, string const &piece_type);
};
