pe5: pe5_main.o LLnode.o
	gcc pe5_main.o LLnode.o -o pe5

pe5_main.o: pe5_main.c
	gcc -c pe5_main.c

LLnode.o: LLnode.c
	gcc -c LLnode.c

clean:
	rm -rf *.o pe5