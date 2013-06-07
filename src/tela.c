#include "tela.h"
#define SERV_ENGINE
#include "engine.h"
#define SERV_PECA
#include "peca.h"

EXT_MOD_TELA Tela* nova_tela () {
	Tela *t;
	int i, j;

	t = (Tela*) malloc(sizeof(Tela));

	t->x = OFFSET_X_TELA;
	t->y = OFFSET_Y_TELA;

	for (i=0; i < TELA_ALTURA; i++){
		for (j=0; j < TELA_LARGURA; j++) {
			t->bloco[i][j] = novo_bloco(j, i, INVISIVEL);
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
	
	for(i=t->x-1; i < 2*TELA_LARGURA+t->x; i+=2)
	{
		set_color(COR_BORDA+1);
		mvaddstr(t->y-1, i, "..");
		mvaddstr(t->y+1 + TELA_ALTURA-1, i, "..");
	}

	for(i=t->y; i <= TELA_ALTURA + t->y + 1; ++i)
	{
		set_color((i%2)+COR_BORDA);
		mvaddstr(i-1, t->x - 2, "..");
		mvaddstr(i-1, t->x + 2*TELA_LARGURA, "..");
	}

	set_color(COR_TELA);
	mvaddstr(t->y/2, t->x + TELA_ALTURA + 3, "Comandos:");
	mvaddstr(t->y/2 + 1, t->x + TELA_ALTURA + 3, "[A]: Move para a esquerda.");
	mvaddstr(t->y/2 + 2, t->x + TELA_ALTURA + 3, "[S]: Move para baixo.");
	mvaddstr(t->y/2 + 3, t->x + TELA_ALTURA + 3, "[D]: Move para a direita.");
	mvaddstr(t->y/2 + 4, t->x + TELA_ALTURA + 3, "[Q]: Sai do jogo");
	mvaddstr(t->y/2 + 5, t->x + TELA_ALTURA + 3, "[ESC]: Pausa o jogo");
}

EXT_MOD_TELA void deleta_tela(Tela* t)
{
	free(t);
}
