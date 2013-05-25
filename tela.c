#define SERV_TELA
#include "tela.h"
#define SERV_PECA
#include "peca.h"

EXT_MOD_TELA Tela nova_tela () {
	Tela t;
	int i, j;

	t.x = 35;
	t.y = 3;

	for (i=0; i < TELA_ALTURA; i++){
		for (j=0; j < TELA_LARGURA; j++) {
			t.bloco[i][j] = novo_bloco(j+t.x, i+t.y, INVISIVEL);
		}

	}

	return t;
}

EXT_MOD_TELA void mostra_tela (Tela* t){

	int i, j;

	for (i = 0; i < TELA_ALTURA; i++){
		for (j=0; j < TELA_LARGURA; j++) {
			mostra_bloco(&(t->bloco[i][j]));
		}
	}

}
