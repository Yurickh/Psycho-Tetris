#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include "menu.h"

#define ENTER 10

// Gera a lista de itens dentro da ncurses a partir da lista de nomes fornecida.
ITEM** create_item(char** options, int n_choices)
{
	int i;
	ITEM** item;

	item = (ITEM**) calloc(n_choices, sizeof(ITEM*));
	for(i=0;i<n_choices;++i)
	{
		item[i] = new_item(options[i], NULL);
		set_item_userptr(item[i], item[i]);
	}

	item[i] = NULL;

	return item;
}

//Cria a tela de menu propriamente dita.
void create_menu(MENU** menu, WINDOW** win_menu, ITEM** item)
{
	*menu = new_menu((ITEM**) item);

	*win_menu = newwin(4,10,20,35);
	keypad(*win_menu, TRUE);

	set_menu_win(*menu, *win_menu);
	set_menu_sub(*menu, derwin(*win_menu, 3, 8, 1, 1));

	set_menu_mark(*menu, CURSOR);
	box(*win_menu, 0, 0);
	refresh();
}

void draw_title(char* title)
{
	mvaddstr(0,0,title);
	refresh();
}

EXT_MOD_MENU int menu(char** options, int n_choices, char* title)
{
	ITEM **item;
	int c, i, p=-1;
	MENU* menu;
	WINDOW* win_menu;

	item = create_item(options, n_choices);
	create_menu(&menu, &win_menu, item);

	draw_title(title);

	post_menu(menu);
	wrefresh(win_menu);

	while(p==-1)
	{
		c = wgetch(win_menu);
		switch(c)
		{
			case KEY_DOWN:
				menu_driver(menu, REQ_DOWN_ITEM);
			break;

			case KEY_UP:
				menu_driver(menu, REQ_UP_ITEM);
			break;

			case ENTER:
			{
				ITEM* cur;

				cur = current_item(menu);
				p = item_index(item_userptr(cur));
				pos_menu_cursor(menu);
			}
			break;
		}
	}

	unpost_menu(menu);
	free_menu(menu);
	for(i=0;i<n_choices;++i)
		free_item(item[i]);
	clear();
	refresh();
	
	return p;
}
