#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CUnit.h"
#include "Basic.h" 
#include "bloco.c"

void adicionar_testes_smo_datas(void);

void teste_DT_Novo_Bloco_Tipo_Invisivel(void)
{
	Bloco resultado;
	resultado = novo_bloco(2,3, INVISIVEL);
	CU_ASSERT_TRUE (resultado.tipo == INVISIVEL);
}

void teste_DT_Novo_Bloco_Tipo_Quadrado(void)
{
	Bloco resultado;
	resultado = novo_bloco(2,3, QUADRADO);
	CU_ASSERT_TRUE (resultado.tipo == QUADRADO);
}

void teste_DT_Novo_Bloco_X(void)
{
	Bloco resultado;
	resultado = novo_bloco(2,3, INVISIVEL);
	CU_ASSERT_TRUE (resultado.x == 2 );
}

void teste_DT_Novo_Bloco_Y(void)
{
	Bloco resultado;
	resultado = novo_bloco(2,3, INVISIVEL);
	CU_ASSERT_TRUE (resultado.y == 3);
}

void  adicionar_testes_smo_datas(void){
	CU_pSuite suite;
	
	suite = CU_add_suite("Testes da smo_datas",NULL,NULL);
	
	CU_ADD_TEST(suite, teste_DT_Novo_Bloco_Tipo_Invisivel);
	CU_ADD_TEST(suite, teste_DT_Novo_Bloco_Tipo_Quadrado);
	CU_ADD_TEST(suite, teste_DT_Novo_Bloco_X);
	CU_ADD_TEST(suite, teste_DT_Novo_Bloco_Y);
	
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
