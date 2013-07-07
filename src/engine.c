#include "engine.h"

#define FPS 10

EXT_MOD_ENGINE void wait(int fps)
{
	static clock_t t0 = 0;
	static clock_t t1;
	clock_t num = CLOCKS_PER_SEC/fps;
	
	t1 = clock() - t0;
	if (t1 < num)
		usleep(num - t1);
	t0 = clock();
}

EXT_MOD_ENGINE void set_color(int id)
{
	attron(COLOR_PAIR(id));
}

EXT_MOD_ENGINE void inicializa_ncurses()
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
	init_pair(1, COLOR_RED, COLOR_BLACK); 		//Quadrado
	init_pair(2, COLOR_BLUE, COLOR_BLACK); 		//L1 (L)
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);	//L2 (_|)
	init_pair(4, COLOR_CYAN, COLOR_BLACK); 		//S1 (S)
	init_pair(5, COLOR_GREEN, COLOR_BLACK);		//S2 (Z)
	init_pair(6, COLOR_WHITE, COLOR_BLACK); 	//T
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK); 	// I
	init_pair(18, COLOR_MAGENTA, COLOR_MAGENTA);//Cor_borda 1
	init_pair(19, COLOR_WHITE, COLOR_WHITE); 	//Cor_borda 2
	init_pair(20, COLOR_WHITE, COLOR_BLACK); 	//Cor padrão
}

//FANÇAUM DE ALINPÁ BÂFÊ flushinp() OXENTE MAI GOD;

EXT_MOD_ENGINE void finaliza_ncurses()
{
	endwin();
}


EXT_MOD_ENGINE int pega_input(int espera)
{
	int a, b;
	clock_t ini;

	wait(FPS);

	ini = clock();
	a = getch();
	b = a;
	while(a==b && clock() < ini + espera)
		b = getch();
	if(a!=b)
		ungetch(b);

	return a;
}
