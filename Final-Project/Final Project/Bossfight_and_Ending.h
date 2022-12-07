#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Player.h"

class BossFight{
public:
	// function prototypes
	int MenuChoice;
	void instructions();
	char askYesNo(std::string question);
	int askNumber(std::string question, int high, int low = 0);
	char humanPiece();
	char opponent(char piece);
	void displayBoard(const std::vector<char>& board);
	char winner(const std::vector<char>& board);
	int humanMove(const std::vector<char>& board, char human);
	int computerMove(std::vector<char> board, char computer);
	void announceWinner(char winner, char computer, char human, Player player);
	void StartTicTacToe(Player player);
};
