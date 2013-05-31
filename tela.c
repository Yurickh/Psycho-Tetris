#include "tela.h"
#define SERV_ENGINE
#include "engine.h"
#define SERV_PECA
#include "peca.h"

EXT_MOD_TELA Tela nova_tela () {
	Tela t;
	int i, j;

	t.x = OFFSET_X_TELA;
	t.y = OFFSET_Y_TELA;

	for (i=0; i < TELA_ALTURA; i++){
		for (j=0; j < TELA_LARGURA; j++) {
			t.bloco[i][j] = novo_bloco(j, i, INVISIVEL);
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

	for(i=t->x; i < 2*TELA_LARGURA+t->x; i+=2)
	{
		set_color(COR_TELA);
		mvaddstr(t->y-1, i, "__");
		mvaddstr(t->y + TELA_ALTURA, i, "--");
	}

	for(i=t->y; i <= TELA_ALTURA + t->y; ++i)
	{
		mvaddch(i, t->x-1, '|');
		mvaddch(i, t->x + 2*TELA_LARGURA, '|');
	}

}
