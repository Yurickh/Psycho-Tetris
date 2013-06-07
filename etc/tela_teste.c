#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CUnit.h"
#include "Basic.h" 
#include "tela.c"

void addTestes_smo_datas();

void teste_DT_verificaNovaTela_X (); /**teste para verificar se a posicao X inicial da tela eh maior que zero*/
void teste_DT_verificaNovaTela_Y (); /**teste para verificar se a posicao Y inicial da tela eh maior que zero*/
void teste_DT_verificaNovaTela_invis (); /**teste para verificar se uma posicao qualquer na tela foi corretamente inicializada como invisivel*/

void teste_DT_verificaNovaTela_X (){
	Tela teste;

	teste = nova_tela();
	CU_ASSERT_TRUE(teste.x);
}

void teste_DT_verificaNovaTela_Y () {
	Tela teste;

	teste = nova_tela();
	CU_ASSERT_TRUE(teste.y);
}

void teste_DT_verificaNovaTela_invis () {
	Tela teste;

	teste = nova_tela();
	CU_ASSERT_TRUE(!teste->bloco[15][8].tipo);
}

void addTestes_smo_datas () {
	CU_pSuite suite;

	suite = CU_add_suite("Testes da smo_datas",NULL,NULL);

	CU_ADD_TEST(suite, teste_DT_verificaNovaTela_X);
	CU_ADD_TEST(suite, teste_DT_verificaNovaTela_Y);
	CU_ADD_TEST(suite, teste_DT_verificaNovaTela_invis);
}

int main () {

	if (CUE_SUCCESS != CU_initialize_registry()) {
    	return CU_get_error();
    }

    addTestes_smo_datas ();

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return (CU_get_error);

}
