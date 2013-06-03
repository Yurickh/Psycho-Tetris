#ifndef TELA_H
#define TELA_H

#ifndef SERV_TELA
#define EXT_MOD_TELA
#else
#define EXT_MOD_TELA extern
#endif

#define TELA_LARGURA 10
#define TELA_ALTURA 20
#define OFFSET_X_TELA 30
#define OFFSET_Y_TELA 1

#include <stdlib.h>
#define SERV_BLOCO
#include "bloco.h"

typedef struct
{
	int x, y;
	Bloco bloco[TELA_ALTURA][TELA_LARGURA];
} Tela;
	
EXT_MOD_TELA Tela* nova_tela ();
EXT_MOD_TELA void mostra_tela (Tela* t);

#endif
