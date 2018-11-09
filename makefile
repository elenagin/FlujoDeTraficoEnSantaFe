trafico: trafico.o ventanas.o senales.o
	gcc -o Trafico.exe trafico.o ventanas.o senales.o `pkg-config --libs gtk+-2.0`

trafico.o: trafico.c
	gcc -c trafico.c `pkg-config --cflags gtk+-2.0`

ventanas.o: ventanas.c
	gcc -c ventanas.c `pkg-config --cflags gtk+-2.0`

senales.o: senales.c
	gcc -c senales.c `pkg-config --cflags gtk+-2.0`

borra:
	rm *.o

todo:
	gcc -g -o Trafico.exe trafico.c ventanas.c senales.c `pkg-config --cflags --libs gtk+-2.0`
