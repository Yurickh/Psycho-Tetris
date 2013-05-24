#include <ncurses.h>

void inicializa_ncurses()
{
	initscr();
	cbreak();
	noecho();
	timeout(0);
	curs_set(0);
}

void finaliza_ncurses()
{
	endwin();
}
