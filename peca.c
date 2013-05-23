#include <time.h>
#include <stdlib.h>
#include "bloco.h"
#include "peca.h"

#define NIL -1

///Função interna que faz a atualização das coordenadas internas dos blocos das peças baseando-se em seu tipo. Não deve ser utilizada externamente, então não foi declarada no peca.h.
void move_blocos_peca(Peca* peca, int x=NIL, int y=NIL)
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

int peca_touching(Peca* p, Tela* t)
{
	int result = 0;
	for(int i = 0; i<4; ++i)
		if(t[p->x][p->y + 1]->tipo == VISIVEL)
			result++;
	return result;
}

Peca nova_peca (Tela* tela, int x, int y)
{
	Peca peca;

	peca.x = x;
	peca.y = y;

	for(int i=0;i<4;i++) 
		peca.bloco = novo_bloco(0, 0, INVISIVEL);

	peca.tipo = rand() % TOT_PECA_TIPOS;

	move_blocos_peca(&peca, x, y);
	
	return peca;
}

void peca_move_x (Peca* peca, int x)
{
	peca->x = x;
	move_blocos_peca(peca, x, NIL);
}

void peca_move_y (Peca* peca, int y)
{
	peca->y = y;
	move_blocos_peca(peca, NIL, y);
}

void mostra_peca(Peca* p, Tela* t)
{
	for(int i=0; i<4; ++i)
		t[p->bloco[i].x][p->bloco[i].y].tipo = VISIVEL;
}

void prende_peca(Peca* p, Tela* t)
{
	while(!peca_touching(p, t))
		peca_move_y(p, p->y+1);
	for(int i=0;i<4;++i)
		t[p->x, p->y]->tipo = VISIVEL;	
}
