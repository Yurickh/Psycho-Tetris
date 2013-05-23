#ifndef BLOCO_H
#define BLOCO_H

#include <stdio.h>
#include <ncurses.h>

enum TipoBloco
 (visivel, invisivel);

struct Bloco{
	int x;
	int y;
	BlocoTipo tipo;
	char vet[2];
};

typedef struct Bloco Bloco;

Bloco novo_bloco(int, int, BlocoTipo);
void mostra_bloco(Bloco*);

#endif
