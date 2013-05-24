all:

exe: main.o menu.o game.o engine.o bloco.o peca.o
	gcc -Wall main.o game.o menu.o engine.o bloco.o peca.o -o exe -lmenu -lncurses

main.o: main.c
	gcc -Wall main.c -c

game.o: game.c game.h
	gcc -Wall game.c -c

menu.o: menu.c menu.h
	gcc -Wall menu.c -c

bloco.o: bloco.c bloco.h
	gcc -Wall bloco.c -c

engine.o: engine.c engine.h
	gcc -Wall engine.c -c

peca.o: peca.c peca.h
	gcc -Wall peca.c -c

clean:
	rm *.o
	rm *~
