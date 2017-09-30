
#To run, put this file together with parser.h, and parser.c
#in the same directory. Run "make". Then the executable
#is "scheme" which just takes a line of input and
#breaks it up into tokens.

schemer: main.o parser.o lexer.o eval.o
	gcc -o schemer main.o parser.o lexer.o eval.o

main.o: main.c
	gcc -c main.c

parser.o: parser.c lexer.c
	gcc -c parser.c lexer.c
	
lexer.o: lexer.c
	gcc -c lexer.c
	
eval.o: eval.c
	gcc -c eval.c
	
clean:
	rm -f *~ *.o *.a

#^^^^^^This space must be a TAB!!.

