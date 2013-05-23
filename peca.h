#ifndef PECA_H
#define PECA_H

#ifdef SERV_PECA
#define EXT_MOD_PECA
#else
#define EXT_MOD_PECA extern
#endif

typedef struct
{
	unsigned int x;
	unsigned int y;
	Bloco bloco[4];
} Peca;

Peca nova_peca(Tela* tela, int x, int y);
void peca_move_x(Peca* peca, int x);
void peca_move_y(Peca* peca, int y);
void mostra_peca(Peca* p);
void prende_peca(Peca* p, Tela* t);

#endif
