#include <time.h>
#include <stdlib.h>
#define SERV_BLOCO
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

EXT_MOD_PECA int peca_touching (Peca* p, Tela* t, char resp)
{
	int result = 0, i;
	switch(resp)
	{
		case 's':
			for(i = 0; i<4; ++i)
			{
				if(t->bloco[p->bloco[i].y + 1][p->bloco[i].x].tipo != INVISIVEL || p->bloco[i].y + 1 >= TELA_ALTURA)
					result++;
				if(t->bloco[p->bloco[i].y][p->bloco[i].x].tipo != INVISIVEL || p->bloco[i].y < 0)
					result++;
			}
		break;

		case 'a':
			for (i=0;i<4;++i)
			{
				if(t->bloco[p->bloco[i].y][p->bloco[i].x-1].tipo != INVISIVEL || p->bloco[i].x-1 < 0)
					result++;
			}
		break;

		case 'd':
			for(i=0;i<4;++i)
			{
				if(t->bloco[p->bloco[i].y][p->bloco[i].x+1].tipo != INVISIVEL || p->bloco[i].x+1 >= TELA_LARGURA)
					result++;
			}
		break;
	}
	return result;
}

EXT_MOD_PECA Peca* nova_peca (Tela* tela, int x, int y)
{
	Peca *peca;
	int i;
	BlocoTipo tipo;

	peca = (Peca*) malloc(sizeof(Peca));

	peca->x = x;
	peca->y = y;

	tipo = 1 + rand() % TOT_PECA_TIPOS;

	for(i=0;i<4;i++) 
		peca->bloco[i] = novo_bloco(0, 0, tipo);

	switch(tipo)
	{
		case QUADRADO:
			peca->bloco[0].x = x;
			peca->bloco[1].x = x+1;
			peca->bloco[2].x = x;
			peca->bloco[3].x = x+1;

			peca->bloco[0].y = y;
			peca->bloco[1].y = y;
			peca->bloco[2].y = y+1;
			peca->bloco[3].y = y+1;
		break;

		case L1:
			peca->bloco[0].x = x;
			peca->bloco[1].x = x+1;
			peca->bloco[2].x = x+1;
			peca->bloco[3].x = x+1;

			peca->bloco[0].y = y;
			peca->bloco[1].y = y;
			peca->bloco[2].y = y+1;
			peca->bloco[3].y = y+2;
		break;

		case L2:
			peca->bloco[0].x = x;
			peca->bloco[1].x = x+1;
			peca->bloco[2].x = x;
			peca->bloco[3].x = x;

			peca->bloco[0].y = y;
			peca->bloco[1].y = y;
			peca->bloco[2].y = y+1;
			peca->bloco[3].y = y+2;
		break;

		case S1:
			peca->bloco[0].x = x;
			peca->bloco[1].x = x;
			peca->bloco[2].x = x+1;
			peca->bloco[3].x = x+1;

			peca->bloco[0].y = y;
			peca->bloco[1].y = y+1;
			peca->bloco[2].y = y+1;
			peca->bloco[3].y = y+2;
		break;

		case S2:
			peca->bloco[0].x = x+1;
			peca->bloco[1].x = x;
			peca->bloco[2].x = x+1;
			peca->bloco[3].x = x;

			peca->bloco[0].y = y;
			peca->bloco[1].y = y+1;
			peca->bloco[2].y = y+1;
			peca->bloco[3].y = y+2;
		break;

		case T:
			peca->bloco[0].x = x;
			peca->bloco[1].x = x;
			peca->bloco[2].x = x+1;
			peca->bloco[3].x = x;

			peca->bloco[0].y = y;
			peca->bloco[1].y = y+1;
			peca->bloco[2].y = y+1;
			peca->bloco[3].y = y+2;
		break;
		case I:
		{
			int i;

			peca->bloco[0].x = x-1;
			peca->bloco[1].x = x;
			peca->bloco[2].x = x+1;
			peca->bloco[3].x = x+2;

			for(i=0;i<4;++i)
				peca->bloco[i].y = y;
		}
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

EXT_MOD_PECA void deleta_peca(Peca* p)
{
	free(p);
}

EXT_MOD_PECA void prende_peca(Peca* p, Tela* t)
{
	int i;
	BlocoTipo tipo;
	tipo = p->bloco->tipo;

	while(!peca_touching(p, t, 's'))
	{
		clear();
		mostra_tela(t);
		mostra_peca(p);
		refresh();
		peca_move_y(p, 1);
		wait(30);
	}
	for(i=0;i<4;++i)
		t->bloco[p->bloco[i].y][p->bloco[i].x].tipo = tipo;
}

EXT_MOD_PECA void roda_peca(Peca* p, char sentido)
{
}
