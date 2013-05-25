#include <ncurses.h>
#include "game.h"

EXT_MOD_GAME void start_game()
{
	while(1)
	{
		printw("oi\n");
		refresh();
	}
}
