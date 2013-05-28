#include <ncurses.h>
#include <time.h>
#define SERV_ENGINE
#include "engine.h"
#include "tela.h"
#define SERV_PECA
#include "peca.h"
#include "game.h"

#define ENTER 10

int endgame(Tela* t)
{
	int i;
	int res = 1;

	for(i=0;i<TELA_LARGURA;++i)
	{
		if(t->bloco[i][0].tipo)
			res*=0;
	}

	return !res;
}

EXT_MOD_GAME void start_game()
{
	Tela *tela;
	Peca *peca;
	int end=0, in;
	WINDOW* main;

	srand(time(NULL));
	*tela = nova_tela();

	while(!end)
	{
		*peca = nova_peca(tela, 5, 0);

		if(peca_touching(peca, tela))
			break;
		
		while(!end)
		{
			mostra_tela(tela);
			mostra_peca(peca);
			refresh();
			in = pega_input(0);

			peca_move_y(peca,1);

			switch(in)
			{
				case 's':
					peca_move_y(peca, 2);
				break;

				case 'a':
					peca_move_x(peca, -1);
				break;

				case 'd':
					peca_move_x(peca, 1);
				break;

				case ENTER:
					prende_peca(peca, tela);
				break;
				
				case 'q': 
				case 'Q':
					end = 1;
				break;			
			}
			clear();
			if(peca_touching(peca, tela))
			{
				prende_peca(peca, tela);
				break;
			}
		}

		if(endgame(tela))
			end = 1;
	}

}
