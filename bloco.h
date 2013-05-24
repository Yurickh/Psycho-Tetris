#ifndef BLOCO_H
#define BLOCO_H

#ifdef SERV_BLOCO
#define EXT_MOD_BLOCO
#else
#define EXT_MOD_BLOCO extern
#endif

#include <ncurses.h>

enum Tipo
 {VISIVEL, INVISIVEL};

typedef enum Tipo BlocoTipo;

struct Bloco{
	int x;
	int y;
	BlocoTipo tipo;
};

typedef struct Bloco Bloco;

EXT_MOD_BLOCO Bloco novo_bloco(int, int, BlocoTipo);
EXT_MOD_BLOCO void mostra_bloco(Bloco*);

#endif
