#include "bloco.h"

void mostra_bloco(Bloco* b)
{
	if(b->tipo == VISIVEL)
		mvaddstr(b->y, b->x, "[]");
}


Bloco novo_bloco(it x, int y, BlocoTipo bTipo)
{
	Bloco bloco;
	bloco.x = x;
	bloco.y = y;
	bloco.tipo = bTipo;

	retun bloco;
}
