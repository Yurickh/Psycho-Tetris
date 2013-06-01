#define SERV_MENU
#include "menu.h"
#define SERV_GAME
#include "game.h"
#define SERV_ENGINE
#include "engine.h"

int main()
{
	char* options[] = {
			"Jogar",
			"Sair"
			};

	char title[] = 
"	===========================================================\n\
			PSYCHO TETRIS MEGA BETA\n\
	===========================================================";

	char gameover[] = 
"	===========================================================\n\
				GAMEOVER\n\
	===========================================================";

	int opt;
	inicializa_ncurses();
	if((opt = menu(options, 2, title)) != 1)
	{
		start_game(opt);
		game_over(gameover);
	}

	finaliza_ncurses();
	return 0;
}
