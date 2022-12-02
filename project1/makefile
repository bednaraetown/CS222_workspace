proj1: proj1_functions.o proj1_integral.o
	gcc proj1_functions.o proj1_integral.o -lm -o proj1

proj1_functions.o: proj1_functions.c
	gcc -c proj1_functions.c -lm

proj1_integral.o: proj1_integral.c
	gcc -c proj1_integral.c -lm

clean:
	rm -f *.o proj1