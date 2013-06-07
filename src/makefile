all:

exe: main.o menu.o game.o engine.o bloco.o peca.o tela.o
	gcc main.o game.o menu.o engine.o bloco.o peca.o tela.o -o exe -lmenu -lncurses

main.o: main.c menu.h game.h engine.h
	gcc main.c -c

tela.o: tela.c tela.h peca.h
	gcc tela.c -c

game.o: game.c game.h engine.h tela.h peca.h
	gcc game.c -c

menu.o: menu.c menu.h
	gcc -Wall menu.c -c

bloco.o: bloco.c bloco.h engine.h tela.h
	gcc bloco.c -c

engine.o: engine.c engine.h
	gcc engine.c -c

peca.o: peca.c peca.h bloco.h
	gcc peca.c -c

teste: teste_bloco tela_teste peca_teste

teste_bloco: teste_bloco.c bloco.h
	gcc -I./CUnit -L./CUnit teste_bloco.c -lcunit -o teste_bloco

tela_teste: tela_teste.c tela.h bloco.h
	gcc -I./CUnit -L./CUnit tela_teste.c -lcunit -o tela_teste

peca_teste: peca_teste.c peca.h
	gcc -I./CUnit -L./Cunit peca_teste.c -lcunit -o peca_teste

clean:
	rm *.o
	rm *~
