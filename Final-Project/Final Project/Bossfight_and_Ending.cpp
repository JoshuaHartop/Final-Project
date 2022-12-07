#include "Bossfight_and_Ending.h"
#include "Player.h"
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
bool isLegal(int move, const std::vector<char>& board);
void BossFight::StartTicTacToe(Player player) {
	int move;
	const int NUM_SQUARES = 9;
	std::vector<char> board(NUM_SQUARES, EMPTY);
	std::cout << "Something appears, out of the corner of your eye you see it, a quick movement, certainly faster than you.\n";
	std::cout << "Along with a shiny glimmer like moonlight on water, as you turn to look at it you are greeted by clanking and metal scraping.\n";
	std::cout << "You watch what looks to be a metal man, as he walks up to you, his eyes lock on you, and you get a horrible feeling in your stomach as he says...\n";

	std::cout << "\n\nGreetings challenger I heard you seek revenge on my, and all monsters ruler?\n";
	std::cout << "[1] Yes\n";
	std::cout << "[2] No\n";
	std::cin >> MenuChoice;

	if (MenuChoice == 1) {
		std::cout << "You are quite unsightly " << player.playerName() << " the " << player.getRace() << "\n";
	}
	else {
		std::cout << "You are " << player.playerName() << " the " << player.getRace() << " an idiot like you can not decieve me, I know what you seek\n";
	}
	std::cout << "While I do not usually make deals with " << player.getRace() << "s like you, I shall make an exception.\nIf you prove your wits greater than mine I will sell out the buffoon that declares herself Queen.\n";
	std::cout << "[1] Queen?\n";
	std::cout << "[2] I accept your challenge\n";
	std::cin >> MenuChoice;

	if (MenuChoice == 1) {
		std::cout << "Were you under the impression that some fiendish brute could lead an army???\n The queen has always held power, but her age is catching up to her, it seems each year of her life takes away part of her brain.\n So I, the smartest in the land, wish to take her place, now lets get this started.\n";
	}
	else {
		std::cout << "Splendid, lets begin \n";
	}
	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(board);

	while (winner(board) == NO_ONE)
	{
		if (turn == human)
		{
			move = humanMove(board, human);
			board[move] = human;
		}
		else
		{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}

	announceWinner(winner(board), computer, human, player);

	
}

void BossFight::instructions()
{
	std::cout << "Welcome to the ultimate man-metal monster showdown: Tic-Tac-Toe.\n";
	std::cout << "--where human brain is pit against the finest steel a monster can wear as skin\n\n";

	std::cout << "Make your move known by entering a number, 0-8. The number\n";
	std::cout << "corresponds to the desired board position, as illustrated:\n\n";

	std::cout << "		0 | 1 | 2\n";
	std::cout << "		3 | 4 | 5\n";
	std::cout << "		6 | 7 | 8\n\n";

	std::cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

char BossFight::askYesNo(std::string question)
{
	char response;
	do
	{
		std::cout << question << " (y/n): ";
		std::cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

int BossFight::askNumber(std::string question, int high, int low)
{
	int number;
	do
	{
		std::cout << question << " (" << low << " - " << high << "): ";
		std::cin >> number;
	} while (number > high || number < low);

	return number;
}

char BossFight::humanPiece()
{
	char go_first = askYesNo("Do you require the first move?");
	if (go_first == 'y')
	{
		std::cout << "\nThen take the first move. You will need it.\n";
		return X;
	}
	else
	{
		std::cout << "\nYour bravery will be your undoing... I will go first.\n";
		return O;
	}
}

char BossFight::opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

void BossFight::displayBoard(const std::vector<char>& board)
{
	std::cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	std::cout << "\n\t" << "--------";
	std::cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	std::cout << "\n\t" << "--------";
	std::cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	std::cout << "\n\t" << "\n\n";
}

char BossFight::winner(const std::vector<char>& board)
{
	// all possible winning rows
	const int WINNING_ROWS[8][3] = { {0, 1, 2},
									{3, 4, 5},
									{6, 7, 8},
									{0, 3, 6},
									{1, 4, 7},
									{2, 5, 8},
									{0, 4, 8},
									{2, 4, 6} };

	const int TOTAL_ROWS = 8;

	// if any winning row has three values that are the same (and not EMPTY),
	// then we have a winner
	for (int row = 0; row < TOTAL_ROWS; ++row)
	{
		if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
		{
			return board[WINNING_ROWS[row][0]];
		}
	}

	// since nobody has won, check for a tie (no empty squares left)
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;

	// since nobody has won and it isn't a tie, the game isn't over
	return NO_ONE;
}

inline bool isLegal(int move, const std::vector<char>& board)
{
	return (board[move] == EMPTY);
}

int BossFight::humanMove(const std::vector<char>& board, char human)
{
	int move = askNumber("Where will you move?", (board.size() - 1));
	while (!isLegal(move, board))
	{
		std::cout << "\nThat square is already occupied, foolish human.\n";
		move = askNumber("Where will you move?", (board.size() - 1));
	}
	std::cout << "Fine...\n";

	return move;
}

int BossFight::computerMove(std::vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;

	// if computer can win on next move, that's the move to make
	while (!found && move < board.size())
	{
		if (isLegal(move, board))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}

		if (!found)
		{
			++move;
		}
	}

	// otherwise, if human can win on next move, that's the move to make
	if (!found)
	{
		move = 0;
		char human = opponent(computer);

		while (!found && move < board.size())
		{
			if (isLegal(move, board))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}

			if (!found)
			{
				++move;
			}
		}
	}

	// otherwise, moving to the best open square is the move to make
	if (!found)
	{
		move = 0;
		unsigned int i = 0;

		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		// pick best open square
		while (!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if (isLegal(move, board))
			{
				found = true;
			}

			++i;
		}
	}

	std::cout << "I shall take square number " << move << std::endl;
	return move;
}

void BossFight::announceWinner(char winner, char computer, char human, Player player)
{
	if (winner == computer)
	{
		std::cout << winner << "s won!\n";
		std::cout << "As I predicted, human, I am triumphant once more, proof that any monster can beat mortal scum like you, now prepare to die\nThe metal man proceeds to lunge at you, to which you spot it, under his clothes his chest is flesh not metal, you have no choice, you take the paper from his body and read it, then once again, then again and again trying to comprehend what you have just seen. . .\n";
	}
	else if (winner == human)
	{
		std::cout << winner << "s won!\n";
		std::cout << "You dirty" << player.getRace() << ", You must’ve cheated”\nThe metal man proceeds to lunge at you, to which you spot it, under his clothes his chest is flesh not metal, you have no choice, you take the paper from his body and read it, then once again, then again and again trying to comprehend what you have just seen. . .\n";

	}
	else
	{
		std::cout << "It's a tie.\n";
		std::cout << "You were most lucky, human, and somehow managed to tie me.\n";
		std::cout << "Celebrate... for this is the last you will ever achieve.\nThe metal man proceeds to lunge at you, to which you spot it, under his clothes his chest is flesh not metal, you have no choice, you take the paper from his body and read it, then once again, then againand again trying to comprehend what you have just seen. . .\n";
	}
}