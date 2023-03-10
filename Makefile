all:
	gcc -o main main.c ADTs/land.c ADTs/terrain.c ADTs/address.c ADTs/person.c ADTs/date.c

run:
	./main

clean:
	rm main

valgrind:
	valgrind ./main

gdb:
	gdb ./main