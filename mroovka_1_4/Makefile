CC = gcc

all: main.o macierz.o mroovka.o obsluga.o grafika.o
	$(CC) main.o macierz.o mroovka.o obsluga.o grafika.o -o test -lpng

main.o: main.c macierz.h obsluga.h mroovka.h
	$(CC) main.c -c -o main.o

macierz.o: macierz.c macierz.h
	$(CC) macierz.c -c -o macierz.o

mroovka.o: mroovka.c mroovka.h macierz.h
	$(CC) mroovka.c -c -o mroovka.o

obsluga.o: obsluga.c obsluga.h mroovka.h macierz.h
	$(CC) obsluga.c -c -o obsluga.o

grafika.o: grafika.c grafika.h macierz.c macierz.h
	$(CC) grafika.c -c -o grafika.o -lpng

clean:
	rm -f *.o test
