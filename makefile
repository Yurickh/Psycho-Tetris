all:

exe: main.o menu.o game.o engine.o bloco.o peca.o tela.o
	gcc main.o game.o menu.o engine.o bloco.o peca.o tela.o -o exe -lmenu -lncurses -g

main.o: main.c menu.h game.h engine.h
	gcc main.c -c

tela.o: tela.c tela.h peca.h
	gcc tela.c -c

game.o: game.c game.h engine.h tela.h peca.h
	gcc game.c -c

menu.o: menu.c menu.h
	gcc -Wall menu.c -c

bloco.o: bloco.c bloco.h engine.h
	gcc bloco.c -c

engine.o: engine.c engine.h
	gcc engine.c -c

peca.o: peca.c peca.h bloco.h
	gcc peca.c -c

clean:
	rm *.o
	rm *~
