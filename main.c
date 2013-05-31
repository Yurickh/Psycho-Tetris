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

	char gameover[] = "GAMEOVER";

	inicializa_ncurses();
	if(!menu(options, 2, title))
	{
		start_game();
		game_over(gameover);
	}

	finaliza_ncurses();
	return 0;
}
