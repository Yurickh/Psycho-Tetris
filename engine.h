#ifndef ENG_H
#define ENG_H

#ifdef SERV_ENG
#define EXT_MOD_ENG
#else
#define EXT_MOD_ENG extern
#endif

#include <ncurses.h>
#include <stdlib.h>

void inicializa_ncurses();
void finaliza_ncurses();
int pega_input(int);


#endif
