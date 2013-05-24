#include "engine.h"	

#define PRENDE 10  /*um enter*/
#define CIMA		259
#define BAIXO		258
#define ESQUERDA	260
#define DIREITA		261

void inicializa_ncurses()
{
	int max_y, max_x;

	initscr();
	start_color();

	
	init_pair(1,COLOR_RED, COLOR_BLACK); /*cor bloco*/
	init_pair(2,COLOR_BLUE, COLOR_BLACK); /*cor tela*/

	getmaxyx(stdscr, max_y, max_x);
	if ((max_y != 24) || (max_x != 80)) {
		endwin();
		printf("Redimensione o terminal para 24 colunas por 80 linhas.\n");
		exit(0);
	}
	cbreak();
	noecho();
	timeout(0);
	curs_set(0);
}

void finaliza_ncurses()
{
	endwin();
}

int pega_input(int input)
{
	switch (input)
	{
		case DIREITA: return KEY_RIGHT ; break;
		case ESQUERDA: return KEY_LEFT ; break;
		case BAIXO: return KEY_DOWN ; break;
		case CIMA: return KEY_UP ; break;
		case PRENDE: return PRENDE ; break;
	}
	return 0;
}
int main()
{
return 0;
}
