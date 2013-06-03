#define SERV_MENU
#include "menu.h"
#define SERV_GAME
#include "game.h"
#define SERV_ENGINE
#include "engine.h"

#define NUM_OPT 2

int main()
{
	//Vetor de opções do menu principal. Pode ser expandido, contanto que seja adaptada a variavel NUM_OPT
	char* options[] = {
			"Jogar",
			"Sair"
			};

	//String que monta a tela de apresentação do menu inicial.
	char title[] = 
"	===========================================================\n\
			PSYCHO TETRIS MEGA BETA\n\
	===========================================================";


	//String que monta a tela de game over.
	char gameover[] = 
"	===========================================================\n\
				GAMEOVER\n\
	===========================================================";

	int opt;
	inicializa_ncurses();
	if((opt = menu(options, NUM_OPT, title)) != 1)
	{
		start_game(opt);
		game_over(gameover);
	}

	finaliza_ncurses();
	return 0;
}
