#ifndef PECA_H
#define PECA_H

#ifdef SERV_PECA
#define EXT_MOD_PECA
#else
#define EXT_MOD_PECA extern
#endif

#define SERV_TELA
#include "tela.h"

#define TOT_PECA_TIPOS 2

/**Estrutura básica de um peça.
Cada peça deve conter suas próprias coordenadas e as coordenadas de cada um de seus blocos.
*/
typedef struct
{
	int x;
	int y;
	Bloco bloco[4];
} Peca;


/// Verifica se a peca em questão está tocando inferiormente alguma outra;
EXT_MOD_PECA int peca_touching(Peca* p, Tela* t, char resp);
/// Cria uma nova peça da forma quadrada.
EXT_MOD_PECA Peca nova_peca(Tela* tela, int x, int y);
/// Move a peça x unidades na horizontal.
EXT_MOD_PECA void peca_move_x(Peca* peca, int x);
/// Move a peça y unidades na vertical.
EXT_MOD_PECA void peca_move_y(Peca* peca, int y);
/// Mostra a peça na tela.
EXT_MOD_PECA void mostra_peca(Peca* p);
/// Prende a peça no fim da tela.
EXT_MOD_PECA void prende_peca(Peca* p, Tela* t);

#endif
