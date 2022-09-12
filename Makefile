all: oo sb

oo: odd_one.o show_bytes.o 
	gcc -o oo odd_one.o 

odd_one.o: odd_one.c
	gcc -c odd_one.c

sb: show_bytes.o 
	gcc -o sb show_bytes.o 

show_bytes.o: show_bytes.c
	gcc -c show_bytes.c

clean:
	-rm *.o oo sb
