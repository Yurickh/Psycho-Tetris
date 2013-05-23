#ifndef PECA_H
#define PECA_H

#ifdef SERV_PECA
#define EXT_MOD_PECA extern
#else
#define EXT_MOD_PECA
#endif

#define TOT_PECA_TIPOS 1
#define QUADRADO 0

/**Estrutura básica de um peça.
Cada peça deve conter suas próprias coordenadas e as coordenadas de cada um de seus blocos.
*/
typedef struct
{
	int x;
	int y;
	int tipo;
	Bloco bloco[4];
} Peca;

/// Cria uma nova peça da forma quadrada.
Peca nova_peca(Tela* tela, int x, int y);
/// Move a peça para a posição x.
void peca_move_x(Peca* peca, int x);
/// Mova a peça para a posição y.
void peca_move_y(Peca* peca, int y);
/// Mostra a peça na tela.
void mostra_peca(Peca* p);
/// Prende a peça no fim da tela.
void prende_peca(Peca* p, Tela* t);

#endif
