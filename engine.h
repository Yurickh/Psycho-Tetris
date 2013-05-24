#ifndef ENG_H
#define ENG_H

#ifdef SERV_ENG
#define EXT_MOD_ENG
#else
#define EXT_MOD_ENG extern
#endif

#include <ncurses.h>
#include <stdlib.h>
#define COR_BLOCO 1
#define COR_TELA 2

/*definir a cor da tela e do bloco*/
EXT_MOD_ENG void inicializa_ncurses();
EXT_MOD_ENG void finaliza_ncurses();
EXT_MOD_ENG int pega_input(int);


#endif
