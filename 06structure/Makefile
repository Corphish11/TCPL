tree: tree.o getword.o ../04function/calc/getch.o

keyword.c: keygen.sh key.txt
	./keygen.sh > keyword.c

kwc.o: keyword.h keyword.c kwc.c


kwc: kwc.o ../04function/calc/getch.o
