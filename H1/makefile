CC = g++
EXE = 1 2

all : $(EXE)

.PHONY : clean
clean :
	rm -f *.o core $(EXE)


1: 1.cpp
	echo "# Generating 1.o"
	$(CC) 1.cpp -o 1

2: 2.cpp
	echo "# Generating 2.o"
	$(CC) 2.cpp -o 2

run_1:
	echo "# Executing Exercise 1:"
	./1

run_2:
	echo "# Executing Exercise 2:"
	./2