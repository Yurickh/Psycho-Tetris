#include "bloco.h"
#define SERV_ENGINE
#include "engine.h"

EXT_MOD_BLOCO void mostra_bloco(Bloco* b)
{
	if(b->tipo != INVISIVEL)
	{
		set_color(b->tipo);
		mvaddstr(b->y, (b->x)*2, "[]");
		set_color(STANDARD);
	}
}


EXT_MOD_BLOCO Bloco novo_bloco(int x, int y, BlocoTipo bTipo)
{
	Bloco bloco;
	bloco.x = x;
	bloco.y = y;
	bloco.tipo = bTipo;

	return bloco;
}
