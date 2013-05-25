#ifdef ENGINE_H
#define ENGINE_H

#ifdef SERV_ENGINE
#define EXT_MOD_ENGINE
#else
#define EXT_MOD_ENGINE extern
#endif

#define STANDARD 10

EXT_MOD_ENGINE void set_color(int);
EXT_MOD_ENGINE void inicializa_ncurses();
EXT_MOD_ENGINE void finaliza_ncurses();
EXT_MOD_ENGINE int pega_input(int);


#endif
