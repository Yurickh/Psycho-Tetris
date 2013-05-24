/**Definiçao de servidor.
Define servidor de engine, que sera usada para inicialização do ncurses e retornar um input	
*/
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

	
	EXT_MOD_ENG void inicializa_ncurses();  //!<Função que inicializa ncurses
	EXT_MOD_ENG void finaliza_ncurses();  //!<Função que finaliza ncurses
	EXT_MOD_ENG int pega_input(int);  //!<Função que retorna o input para a operação do jogo

#endif
