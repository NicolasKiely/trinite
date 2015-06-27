cc=gcc -Wall -Wpedantic

bin/trinite: src/main.c obj/lexer.o
	$(cc) -o bin/trinite src/main.c obj/lexer.o

obj/lexer.o: src/lexer.h src/lexer.c
	$(cc) -o obj/lexer.o -c src/lexer.c
