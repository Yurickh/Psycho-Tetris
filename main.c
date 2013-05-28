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
			"Sair",
			"Bankai"
			};

	char title[] = 
"	===========================================================\n\
			PSYCHO TETRIS MEGA BETA\n\
	===========================================================";

	inicializa_ncurses();
	if(!menu(options, 3, title))
		start_game();

	finaliza_ncurses();
	return 0;
}
