#include <time.h>
#include <stdlib.h>
#include "bloco.h"
#include "peca.h"

///Função interna que faz a atualização das coordenadas internas dos blocos das peças baseando-se em seu tipo. Não deve ser utilizada externamente, então não foi declarada no peca.h.
void move_blocos_peca(Peca* peca, int x, int y)
{
	int i;
	for(i=0;i<4;i++)
	{
		peca->bloco[i].x += x;
		peca->bloco[i].y += y;
	}
}

EXT_MOD_PECA int peca_touching(Peca* p, Tela* t)
{
	int result = 0, i;
	for(i = 0; i<4; ++i)
		if(t->bloco[p->x][p->y + 1].tipo != INVISIBLE)
			result++;
	return result;
}

EXT_MOD_PECA Peca nova_peca (Tela* tela, int x, int y)
{
	Peca peca;
	int i;

	peca.x = x;
	peca.y = y;

	peca.tipo = rand() % TOT_PECA_TIPOS;

	for(i=0;i<4;i++) 
		peca.bloco[i] = novo_bloco(0, 0, peca.tipo);

	switch(peca.tipo)
	{
		case QUADRADO:
			peca.bloco[0].x = x;
			peca.bloco[1].x = x+1;
			peca.bloco[2].x = x;
			peca.bloco[3].x = x+1;

			peca.bloco[0].y = y;
			peca.bloco[1].y = y;
			peca.bloco[2].y = y+1;
			peca.bloco[3].y = y+1;
		break;
	}
	
	return peca;
}

EXT_MOD_PECA void peca_move_x (Peca* peca, int x)
{
	peca->x += x;
	move_blocos_peca(peca, x, 0);
}

EXT_MOD_PECA void peca_move_y (Peca* peca, int y)
{
	peca->y += y;
	move_blocos_peca(peca, 0, y);
}

EXT_MOD_PECA void mostra_peca(Peca* p)
{
	int i;
	for(i=0; i<4; ++i)
		mostra_bloco(&(p->bloco[i]));
}

EXT_MOD_PECA void prende_peca(Peca* p, Tela* t)
{
	int i;
	while(!peca_touching(p, t))
		peca_move_y(p, 1);
	for(i=0;i<4;++i)
		t->bloco[p->bloco[i].x][p->bloco[i].y].tipo = p->tipo;
}
