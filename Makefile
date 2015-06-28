cc=gcc -Wall -Wpedantic
vg=valgrind --leak-check=yes --error-exitcode=1

###############################################################################
# Primary Targets
###############################################################################
bin/trinite: src/main.c test/lexer.pass
	$(cc) -o bin/trinite src/main.c obj/lexer.o



###############################################################################
# Testing Binaries
###############################################################################

test/lexer.pass: src/test_lexer.c obj/lexer.o
	$(cc) -o test/lexer src/test_lexer.c obj/lexer.o
	$(vg) test/lexer



###############################################################################
# Intermediate files
###############################################################################

obj/lexer.o: src/lexer.h src/lexer.c
	$(cc) -o obj/lexer.o -c src/lexer.c
