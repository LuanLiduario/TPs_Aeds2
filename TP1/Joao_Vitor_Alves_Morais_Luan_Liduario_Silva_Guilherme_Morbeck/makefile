all: main clear

main: Usuario.o main.o
	gcc Usuario.o main.o -o main

main.o: main.c Usuario.h
	gcc -g -c main.c

Usuario.o: Usuario.c Usuario.h
	gcc -g -c Usuario.c

clear:
	rm *.o