CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=mybank.o
FLAGS= -Wall -g

all:  libmyBank.a main	
main: $(OBJECTS_MAIN) libmyBank.a 
	$(CC) $(FLAGS) -o main $(OBJECTS_MAIN) libmyBank.a
libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o	
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so main
