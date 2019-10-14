CC = g++
EXE = h3
OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

all : $(EXE)

.PHONY : clean

clean :
	rm -f *.o core $(EXE)

h3: h3.o greyscale.o
	$(CC) -Wall h3.o greyscale.o -o h3 $(LIBS)

h3.o: h3.cpp
	$(CC) -c h3.cpp $(LIBS)

greyscale.o: greyscale.cpp greyscale.h
	$(CC) -c greyscale.cpp $(LIBS)

run:
	echo "# Executing Exercise h3 with test_asc.dat:"
	./h3 test_asc.dat



