#define PRENDE 10  /*um enter*/
#define CIMA		259
#define BAIXO		258
#define ESQUERDA	260
#define DIREITA		261

#include <stdlib.h>
#include <ncurses.h>
#include "engine.h"

void set_color(int id)
{
	attron(COLOR_PAIR(id));
}

void inicializa_ncurses()
{
	int max_y, max_x;

	initscr();

	getmaxyx(stdscr, max_y, max_x);
	if ((max_y != 24) || (max_x != 80)) {
		endwin();
		printf("Erro ):\nRedimensione o terminal para 80 colunas por 24 linhas.\n");
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

int pega_input(int espera)
{
	return getch();
}
