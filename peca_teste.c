#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CUnit.h"
#include "Basic.h" 
#include "peca.c"

void adicionar_testes_smo_datas();

void teste_DT_NovaPeca_coordX ();
void teste_DT_NovaPeca_coordY ();
void teste_DT_NovaPeca_tipo ();
void teste_DT_moveBlocosPeca ();
void teste_DT_pecaTouching ();

void teste_DT_NovaPeca_coordY () {
	Tela* t;
	Peca* p;

	t = nova_tela();
	p = nova_peca(t, 0, 3);
	CU_ASSERT_TRUE (p.y == 3);
}

void teste_DT_NovaPeca_coordX () {
	Tela* t;
	Peca* p;

	t = nova_tela();
	p = (t, 4, 3);

	CU_ASSERT_TRUE (p.x == 4);
}

void teste_DT_NovaPeca_tipo () {
	Tela* t;
	Peca* p;

	t = nova_tela();
	p = nova_peca(t, 2, 0);

	CU_ASSERT_TRUE (p.tipo != INVISIVEL);
}

void teste_DT_moveBlocosPeca () {
	Tela* t;
	Peca* p;

	t = nova_tela();
	p = nova_peca(t, 0, 3);
	move_blocos_peca(p, 1, 0);

	CU_ASSERT_TRUE (p.x == 1);

}

void teste_DT_pecaTouching () {
	Tela *t;
	Peca* p;
	int r;

	t = nova_tela();
	p = nova_peca(t, 0, 0);

	r = peca_touching(p, t, 's');

	CU_ASSERT_TRUE (r > 0);

}

void  adicionar_testes_smo_datas() {
	CU_pSuite suite;
	
	suite = CU_add_suite("Testes da smo_datas",NULL,NULL);
	
	CU_ADD_TEST(suite, teste_DT_pecaTouching);
	CU_ADD_TEST(suite, teste_DT_moveBlocosPeca);
	CU_ADD_TEST(suite, teste_DT_NovaPeca_tipo);
	CU_ADD_TEST(suite, teste_DT_NovaPeca_coordX);
	CU_ADD_TEST(suite, teste_DT_NovaPeca_coordY);

}

int main ()
{
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();

   	adicionar_testes_smo_datas();
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();

}
