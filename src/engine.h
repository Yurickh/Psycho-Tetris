/**Definiçao de servidor.
Define servidor de engine, que sera usada para inicialização do ncurses e retornar um input	
*/
#ifndef ENGINE_H
#define ENGINE_H

#ifdef SERV_ENGINE
#define EXT_MOD_ENGINE
#else
#define EXT_MOD_ENGINE extern
#endif

#define COR_TELA 20
#define STANDARD 0

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

EXT_MOD_ENGINE void wait(int); //!<Função que participa do controle de fps
EXT_MOD_ENGINE void set_color(int); //!<Função que atribui um par de cores
EXT_MOD_ENGINE void inicializa_ncurses();//!<Função que inicializa ncurses
EXT_MOD_ENGINE void finaliza_ncurses(); //!<Função que finaliza ncurses
EXT_MOD_ENGINE int pega_input(int); //!<Função que retorna o input para a operação do jogo


#endif
