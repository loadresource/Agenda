all: main.o agenda.o
	gcc main.o agenda.o -o main

agenda.o: agenda.h contacto.h agenda.c
	gcc -c agenda.c

main.o: main.c agenda.h contacto.h agenda.c
	gcc -c main.c

clean:
	rm *.o
	rm main