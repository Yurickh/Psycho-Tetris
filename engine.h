/**Definiçao de servidor.
Define servidor de engine, que sera usada para inicialização do ncurses e retornar um input	
*/
#ifdef ENGINE_H
#define ENGINE_H

#ifdef SERV_ENGINE
#define EXT_MOD_ENGINE
#else
#define EXT_MOD_ENGINE extern
#endif

#define STANDARD 0

EXT_MOD_ENGINE int wait(void); //!<Função que participa do controle de fps
EXT_MOD_ENGINE void set_color(int); //!<Função que atribui um par de cores
EXT_MOD_ENGINE void inicializa_ncurses();//!<Função que inicializa ncurses
EXT_MOD_ENGINE void finaliza_ncurses(); //!<Função que finaliza ncurses
EXT_MOD_ENGINE int pega_input(int); //!<Função que retorna o input para a operação do jogo


#endif
