sep: main.o
	gcc -o sep main.o
	make clean

main.o: main.c
	gcc -c main.c

clean:
	rm *.o

run:
	./sep
