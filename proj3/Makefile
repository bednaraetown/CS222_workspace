all: proj3

proj3: proj3_main.o Point.o Rectangle.o
	gcc proj3_main.o Point.o Rectangle.o -lm -o proj3

proj3_main.o: proj3_main.c
	gcc -c proj3_main.c -lm

Point.o: Point.c
	gcc -c Point.c -lm

Rectangle.o: Rectangle.c
	gcc -c Rectangle.c -lm

clean:
	rm -f *.o proj3