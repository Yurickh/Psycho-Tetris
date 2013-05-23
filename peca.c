#include <time.h>
#include <stdlib.h>
#include "bloco.h"
#include "peca.h"

#define NIL -1

///Função interna que faz a atualização das coordenadas internas dos blocos das peças baseando-se em seu tipo. Não deve ser utilizada externamente, então não foi declarada no peca.h.
void atualiza_blocos(Peca* peca, int x=NIL, int y=NIL)
{
	switch(peca->tipo)
	{
		case QUADRADO:
			if(x!=NIL)
			{
				peca->bloco[0].x = x+1;
				peca->bloco[1].x = x+2;
				peca->bloco[2].x = x+1;
				peca->bloco[3].x = x+2;
			}
			if(y!=NIL)
			{
				peca->bloco[0].y = y+1;
				peca->bloco[1].y = y+1;
				peca->bloco[2].y = y+2;
				peca->bloco[3].y = y+2;
			}
		break;
		default:
			exit(1);
	}
}

Peca nova_peca (Tela* tela, int x, int y)
{
	Peca peca;

	peca.x = x;
	peca.y = y;

	for(int i=0;i<4;i++) 
		peca.bloco = novo_bloco(0, 0, INVISIVEL);

	srand(time(NULL));
	peca.tipo = rand() % TOT_PECA_TIPOS;

	atualiza_blocos(&peca, x, y);
	
	return peca;
}

void peca_move_x (Peca* peca, int x)
{
	peca->x = x;
	atualiza_blocos(peca, x, NIL);
}

void peca_move_y (Peca* peca, int y)
{
	peca->y = y;
	atualiza_blocos(peca, NIL, y);
}


