#ifndef GAME_H
#define GAME_H

#ifdef SERV_GAME
#define EXT_MOD_GAME
#else
#define EXT_MOD_GAME extern
#endif

EXT_MOD_GAME void start_game(void);
EXT_MOD_GAME void game_over(char*);

#endif
