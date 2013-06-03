#ifndef GAME_H
#define GAME_H

#ifdef SERV_GAME
#define EXT_MOD_GAME
#else
#define EXT_MOD_GAME extern
#endif

///Main Game Loop
EXT_MOD_GAME void start_game(int);
///Mostra a tela de game over.
EXT_MOD_GAME void game_over(char*);

#endif
