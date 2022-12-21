#pragma once
#include "GameState.hpp"
#include <string>
#include <sstream>
using std::ostream;
using std::string;

class GamePiece {
  GameState* currGame;
  string player;
  string play_piece;

 public:
  GamePiece(string const& play, string const& piece, GameState* state);
  GamePiece(GamePiece const& s);
  ~GamePiece();
  string GetPlayer();
  string GetType();
  int GetPower() const;
  int GetSpeed() const;

  bool operator==(const GamePiece& obj) const;
  bool operator<(const GamePiece& rhs) const;
  bool operator>(const GamePiece& rhs) const;
  bool operator<=(const GamePiece& rhs) const;
  bool operator>=(const GamePiece& rhs) const;
  bool operator!=(const GamePiece& rhs) const;
  GamePiece& operator=(GamePiece obj);
  friend ostream& operator<<(ostream& oss, GamePiece const& obj);
};
