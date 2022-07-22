guiao0: main.o f.o
	 gcc -g -Wall main.o f.o -o guiao0

main.o: main.c head.h
	 gcc -g -c main.c

f.o: f.c head.h
	 gcc -g -c f.c

clean:
	 rm -f guiao0 main.o f.o
