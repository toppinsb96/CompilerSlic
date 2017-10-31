a.out: parser.yy scanner.l main.c symbol.c gen.c
	flex scanner.l
	bison -y -d parser.yy
	gcc -g3 lex.yy.c y.tab.c gen.c symbol.c main.c -ll

clean:
	rm -f a.exe a.out lex.yy.c y.tab.c y.tab.h
