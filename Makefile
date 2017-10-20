a.out: parser.yy scanner.l main.c symbol.c
	flex scanner.l
	bison -y -d parser.yy
	gcc lex.yy.c y.tab.c symbol.c main.c -ll

clean:
	rm -f a.exe a.out lex.yy.c y.tab.c y.tab.h
