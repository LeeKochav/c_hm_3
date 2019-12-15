
all: txtfind isort

txtfind:txtfind.o 
	gcc -Wall -o txtfind txtfind.o

isort:isort.o 
	gcc -Wall -o isort isort.o

isort.o: isort.c isort.h
	gcc -Wall -c isort.c

txtfind.o: txtfind.c txtfind.h
	gcc -Wall -c txtfind.c

.PHONY: clean all 

clean:
	rm -f *.o isort txtfind

