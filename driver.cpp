#include "Game.h"

using namespace std; 

int main() {

	srand(time(NULL)); 
	Game game;
	game.set_up();
	

	bool play_game = true;
	while (play_game == true) {
		game.take_turn(play_game);
	}

	if (game.get_bank() >= 1000000) {
		cout << endl;
		cout << "\033[33m You won the game! You're a millionaire! \033[0m";
		cout << endl;
	}
	else if (game.get_bank() <= 0) {
		cout << endl;
		cout << "\033[31m You lost the game! Better luck next time \033[0m";
		cout << endl;
	}

	return 0;
}
