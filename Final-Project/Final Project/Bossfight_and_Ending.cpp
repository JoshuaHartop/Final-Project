#include "Bossfight_and_Ending.h"
#include "Player.h"
#include "Item.h"
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void BossFight::StartTicTacToe(Player player) {
	int move;
	const int NUM_SQUARES = 9;
	std::vector<char> board(NUM_SQUARES, EMPTY);
	std::cout << "Something appears, out of the corner of your eye you see it, a quick movement, certainly faster than you.\n";
	std::cout << "Along with a shiny glimmer like moonlight on water.\n";
	std::cout << "As you turn to look at it you are greeted by clanking and metal scraping.\n";
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
	std::cout << "The dead humans tally in the thousands, my plan has worked and we will soon attack Riverbrook.\n";
	std::cout << "I’ve infiltrated the town and befriended our opponent, its name is "<< player.playerName() << ", I will attack it soon, and should it figure me out I will have to fight it.\n";
	std::cout << "If any monster comes to town make sure its true identity is known to me, I am calling myself -Josephine- that is how they will find me.\n";
	std::cout << "Kill as many as you can, that wander into the darkness, those are your orders.\n";
	std::cout << "Tetsutetsu you are my most trusted scientist, keep your metal skin on at all times.";
	std::cout << "Should it become necessary I have put the monster antidote in your coat.\n";
	std::cout << "The antitode shall allow you to borrow my powerand turn back into a human, do not let me down.\n";
	StartBossFightScene(player);
}

void BossFight::instructions() {
	std::cout << "Welcome to the ultimate man-metal monster showdown: Tic-Tac-Toe.\n";
	std::cout << "--where human brain is pit against the finest steel a monster can wear as skin\n\n";

	std::cout << "Make your move known by entering a number, 0-8. The number\n";
	std::cout << "corresponds to the desired board position, as illustrated:\n\n";

	std::cout << "		0 | 1 | 2\n";
	std::cout << "		3 | 4 | 5\n";
	std::cout << "		6 | 7 | 8\n\n";

	std::cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

char BossFight::askYesNo(std::string question) {
	char response;
	do {
		std::cout << question << " (y/n): ";
		std::cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

int BossFight::askNumber(std::string question, int high, int low) {
	int number;
	do {
		std::cout << question << " (" << low << " - " << high << "): ";
		std::cin >> number;
	} while (number > high || number < low);

	return number;
}

char BossFight::humanPiece() {
	char go_first = askYesNo("Do you require the first move?");
	if (go_first == 'y') {
		std::cout << "\nThen take the first move. You will need it.\n";
		return X;
	}
	else {
		std::cout << "\nYour bravery will be your undoing... I will go first.\n";
		return O;
	}
}

char BossFight::opponent(char piece) {
	if (piece == X) {
		return O;
	}
	else {
		return X;
	}
}

void BossFight::displayBoard(const std::vector<char>& board) {
	std::cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	std::cout << "\n\t" << "--------";
	std::cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	std::cout << "\n\t" << "--------";
	std::cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	std::cout << "\n\t" << "\n\n";
}

char BossFight::winner(const std::vector<char>& board) {
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
	for (int row = 0; row < TOTAL_ROWS; ++row) {
		if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]])) {
			return board[WINNING_ROWS[row][0]];
		}
	}
	// since nobody has won, check for a tie (no empty squares left)
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;

	// since nobody has won and it isn't a tie, the game isn't over
	return NO_ONE;
}

inline bool BossFight::isLegal(int move, const std::vector<char>& board) {
	return (board[move] == EMPTY);
}

int BossFight::humanMove(const std::vector<char>& board, char human) {
	int move = askNumber("Where will you move?", (board.size() - 1));
	while (!isLegal(move, board)) {
		std::cout << "\nThat square is already occupied, foolish human.\n";
		move = askNumber("Where will you move?", (board.size() - 1));
	}
	std::cout << "Fine...\n";

	return move;
}

int BossFight::computerMove(std::vector<char> board, char computer) {
	unsigned int move = 0;
	bool found = false;

	// if computer can win on next move, that's the move to make
	while (!found && move < board.size()) {
		if (isLegal(move, board)) {
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}

		if (!found) {
			++move;
		}
	}

	// otherwise, if human can win on next move, that's the move to make
	if (!found) {
		move = 0;
		char human = opponent(computer);

		while (!found && move < board.size()) {
			if (isLegal(move, board)) {
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}

			if (!found) {
				++move;
			}
		}
	}

	// otherwise, moving to the best open square is the move to make
	if (!found) {
		move = 0;
		unsigned int i = 0;

		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		// pick best open square
		while (!found && i < board.size()) {
			move = BEST_MOVES[i];
			if (isLegal(move, board)) {
				found = true;
			}

			++i;
		}
	}

	std::cout << "I shall take square number " << move << std::endl;
	return move;
}

void BossFight::announceWinner(char winner, char computer, char human, Player player) {
	if (winner == computer) {
		std::cout << winner << "s won!\n";
		std::cout << "As I predicted, human, I am triumphant once more, proof that any monster can beat mortal scum like you, now prepare to die\nThe metal man proceeds to lunge at you, to which you spot it, under his clothes his chest is flesh not metal, you have no choice, you take the paper from his body and read it, then once again, then again and again trying to comprehend what you have just seen. . .\n";
	}
	else if (winner == human) {
		std::cout << winner << "s won!\n";
		std::cout << "You dirty " << player.getRace() << ", You must’ve cheated-\nThe metal man proceeds to lunge at you, to which you spot it, under his clothes his chest is flesh not metal, you have no choice, you take the paper from his body and read it, then once again, then again and again trying to comprehend what you have just seen. . .\n";

	}
	else {
		std::cout << "It's a tie.\n";
		std::cout << "You were most lucky, human, and somehow managed to tie me.\n";
		std::cout << "Celebrate... for this is the last you will ever achieve.\nThe metal man proceeds to lunge at you, to which you spot it, under his clothes his chest is flesh not metal, you have no choice, you take the paper from his body and read it, then once again, then againand again trying to comprehend what you have just seen. . .\n";
	}
}
void BossFight::StartBossFightScene(Player player) {
	char FightChoice;
	std::cout << "\nYou stumble back to town, your mind blank from shock, and you are greeted by that familiar voice...\n\n";
	std::cout << "-Hey " << player.playerName() << ", how are you doing, I haven’t checked up on you in a while, have I?-\n";
	std::cout << "[1] How could you do this to us ?\n";
	std::cout << "[2] Pull out your sword.\n";
	std::cout << "[3] I know who you are.\n\n";
	std::cin >> MenuChoice;
	std::cout << "- So, you have figured it out, -says - Josephine - in that familiar shrill scream, -death is the fate of all you mortals, I am simply showing you the mercy of not making you wait-.\n";
	std::cout << "\nPress a button to muster all your strength into an attack\n";
	std::cin >> FightChoice;
	std::cout << "-You cannot win" << player.playerName() << ", you are to weak!-\n";
	std::cin >> FightChoice;
	std::cout << "-You pose no threat to me, all you’ve done is caused the massacre I will unleash-\n";
	std::cin >> FightChoice;
	std::cout << "-These buildings were taken from my home, the trees cut down, the water tarnished with chemicals from your peoples factories.-\n";
	std::cin >> FightChoice;
	std::cout << "-We are not the monsters, you are the one doing the killing.-\n";
	std::cin >> FightChoice;
	std::cout << "-Who sold me out, I’ll rip the meat off their bones and feed it to the wolves, the same will happen to you!-\n";
	std::cin >> FightChoice;
	std::cout << "-Blood? Blood in my cough? What type of magic are you using on me?-\n";
	std::cout << "-So *cough* you think you can beat us all ? I may die but we will survive, all your sacrifice means nothing.\n";
	std::cout << "It does not affect our numbers, you will perish- to which you reply\n";
	std::cout << "-One by one I massacre your army, I will not die to a monsters hand, and certainly not yours. - \n";
	std::cout << "As she lets out her final breath she says -at what cost- you turn around and see hundreds of monsters rushing in from the forests.\n";
	std::cout << "They are here to kill every villager, the fight has been brought to you.\n";
	std::cout << "You black out from exhaustion, in a pool of your own blood after leveling their forces, awakening in a familiar inn, with a familiar face.\n";
	std::cout << " -JOSEPHINE!- You scream as the dead stares you in the eyes. - Yes, and thank you for saving my town.\n";
	std::cout << "It is so nice to finally meet you, I have been locked in my own house so long I barely remembered what the town looked like.-\n";
	std::cout << "- Are they dead ? -you ask, with tears running down your face, as you finally take a break for the first time in 2 months.\n";
	std::cout << "-Not all of them, the rest have retreated, but they will gang up to try and survive, we need someone brave enough to adventure into the forest.\n";
	std::cout << "For the safety of our civilization, I ask of you to help us protect our people-You think, and you think, then you think some more.\n";
	std::cout << "All you can think of to say is -I will defend Riverbrook and its People, with all my might-\n";
	std::cout << "\nPlay Credits y/n\n";
	do {
		std::cin >> FightChoice;
		if (FightChoice == 'Y' || FightChoice == 'y') {
			std::cout << "\n\n\n\n";
			std::cout << "Programmers: Josh Hartop, Ryan Degen                      Voice Actors : Ryan Degen, Josh Hartop\n\n";
			std::cout << "Graphics Programmers: Josh Hartop, Ryan Degen                            Teacher: Dennis Hubley\n\n";
			std::cout << "Cameo as Monster Queen V/A: Ashton Vansnick   Cameo as Knight of The Monster Queen: Deven Hyson\n\n";
			std::cout << "Writers:Ryan Degen (Story), Josh Hartop (Riverbrook)            Dev Platform (git): GitHub, inc\n\n";
			std::cout << "       Developped in visual studio, hastily finished because we forgot things at the end.      \n";
			std::cout << "                                           [Game Name]                                         \n";
			std::cout << "Heading back to town\n";
			std::cout << "\n\n\n\n\n\n-I hope you've healed enough to fight, the monster queen also dropped some gear if you want it " << player.playerName() << "- Said Josephine\n";
			std::cout << "Press [V] uppercase to leave.\n";
			FightChoice == 'V';
		}
		else if (FightChoice == 'N' || FightChoice == 'n') {
			std::cout << "\n\n\n\n\n\n-I hope you've healed enough to fight, the monster queen also dropped some gear if you want it " << player.playerName() << "- Said Josephine\n";
			std::cout << "Press [V] uppercase to leave.\n";
			FightChoice == 'V';
		}
		else {
			std::cout << "Please enter valid input.\n";
		}
	} while (FightChoice != 'V');
}   