#ifndef MOD_TELA_H
#define MOD_TELA_H

	#ifndef SERV_TELA
		#define EXT_MOD_TELA
	#else
		#define EXT_MOD_TELA extern
	#endif

			#include <stdio.h>
			#include <stdlib.h>
			#include "tela.c"

			typedef struct tela Tela;
			
			EXT_MOD_TELA Tela nova_tela ();
			EXT_MOD_TELA void mostra_tela (Tela* t);

#endif