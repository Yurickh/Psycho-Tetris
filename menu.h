#ifndef MENU_H
#define MENU_H

#ifdef SERV_MENU
#define EXT_MOD_MENU
#else
#define EXT_MOD_MENU extern
#endif

#define CURSOR ">"

/**Cria o menu principal.
Retorna um inteiro n, onde n é o índice da opção selecionada pelo usuário.*/
EXT_MOD_MENU int menu(char** options, int n_choices, char* title);

#endif
