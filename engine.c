#define DIREITA 261
#define BAIXO 258
#define ESQUERDA 260
#define PRENDE 10  /*um enter*/
#define ROTACIONA 'r'

void inicializa_ncurses()
{
	int max_y, max_x;

	initscr();

	getmaxyx(stdscr, max_y, max_x);
	if ((max_y != 24) || (max_x != 80)) {
		endwin();
		printf("Redimensione o terminal para 80 colunas por 24 linhas.\n");
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
		case DIREITA: return 1 ; break;
		case ESQUERDA: return 2 ; break;
		case BAIXO: return 3 ; break;
		case ROTACIONA: return 4 ; break;
		case PRENDE: return 5 ; break;
	}
	return 0;
}
