#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "engine.h"

#define FPS 10

int wait(int fps)
{
	static clock_t t0 = 0;
	static clock_t t1;
	clock_t num = CLOCKS_PER_SEC/fps;
	
	t1 = clock() - t0;
	if (t1 < num)
		usleep(num - t1);
	t0 = clock();
}

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
	keypad(stdscr, FALSE);

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK); //Quadrado
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
}

void finaliza_ncurses()
{
	endwin();
}

int pega_input(int espera)
{
	wait(FPS);
	return getch();
}
