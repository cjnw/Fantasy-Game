# Fantasy-Game
Fantasy Game where players can create pieces of the types Wizard, Scout, and Warrior, to do battle.

Each piece type has its own specific attributes, which determines if any given piece is killed or survives a confrontation.

GamePiece.cpp - Contains the means to create pieces to add the current game while it is being played, but also a deconstructor, to destroy pieces that fall in battle. Also holds several overloaded operators to manage the confrontations (comparison operators) between the pieces and determine the winner of each bout.

GameState.cpp - Maintains the state of the current game being played; is also used to manage the ownership and status of each player's game pieces. It is responsible for removing pieces from players based on the outcome of confrontations, as well as adding them.
