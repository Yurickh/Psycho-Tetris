all:

bloco.o: bloco.c bloco.h
	gcc -Wall bloco.c -c

engine.o: engine.c engine.h
	gcc -Wall engine.c -c

peca.o: peca.c peca.h
	gcc -Wall peca.c -c

clean:
	rm *.o
	rm *~
