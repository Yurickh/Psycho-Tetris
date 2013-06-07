/**Definição de servidor.
Define o servidor de Bloco que sera usado para formar a tela e as peças.*/
#ifndef BLOCO_H
#define BLOCO_H

#ifdef SERV_BLOCO
#define EXT_MOD_BLOCO
#else
#define EXT_MOD_BLOCO extern
#endif

#define TOT_PECA_TIPOS 7

typedef enum
{INVISIVEL, QUADRADO, L1, L2, S1, S2, T, I} BlocoTipo;

struct Bloco{
	int x;
	int y;
	BlocoTipo tipo;
};

typedef struct Bloco Bloco;

EXT_MOD_BLOCO Bloco novo_bloco(int, int, BlocoTipo);//!<Função que cria bloco
EXT_MOD_BLOCO void mostra_bloco(Bloco*);//!<Função que mostra os blocos

#endif
