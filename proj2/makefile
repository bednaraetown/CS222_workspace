proj2: proj2_functions.o proj2_histogram.o
	gcc proj2_functions.o proj2_histogram.o -lm -o proj2

proj2_functions.o: proj2_functions.c
	gcc -c proj2_functions.c -lm

proj2_histogram.o: proj2_integral.c
	gcc -c proj2_integral.c -lm

clean:
	rm -f *.o proj2