#ifndef BLOCO_H
#define BLOCO_H

#include <stdio.h>
#include <ncurses.h>

enum BlocoTipo
 (VISIVEL, INVISIVEL);

struct Bloco{
	int x;
	int y;
	BlocoTipo tipo;
};

typedef struct Bloco Bloco;

Bloco novo_bloco(int, int, BlocoTipo);
void mostra_bloco(Bloco*);

#endif
