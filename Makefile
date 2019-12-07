
all: isort.o 
	gcc -Wall -o isort isort.o 

isort.o: isort.c isort.h
	gcc -Wall -c isort.c

.PHONY: clean all 

clean:
	rm -f *.o all

