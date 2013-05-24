#include "bloco.h"
#include "engine.h"

void mostra_bloco(Bloco* b)
{
	if(b->tipo != INVISIVEL)
	{
		set_color(b->tipo);
		mvaddstr(b->y, b->x, "[]");
		set_color(STANDARD);
	}
}


Bloco novo_bloco(int x, int y, BlocoTipo bTipo)
{
	Bloco bloco;
	bloco.x = x;
	bloco.y = y;
	bloco.tipo = bTipo;

	return bloco;
}
