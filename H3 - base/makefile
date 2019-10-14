CC = g++
EXE = h3

all : $(EXE)

.PHONY : clean

clean :
	rm -f *.o core $(EXE)

h3: h3.o greyscale.o
	$(CC) -Wall h3.o greyscale.o -o h3

h3.o: h3.cpp
	$(CC) -c h3.cpp

greyscale.o: greyscale.cpp greyscale.h
	$(CC) -c greyscale.cpp

run:
	echo "# Executing Exercise h3 with test_asc.dat:"
	./h3 test_asc.dat



