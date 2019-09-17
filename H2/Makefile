CXX = g++
DEPS = poly.h
OBJ = poly.o h2.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $<

h2: $(OBJ) $(DEPS)
	$(CXX) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o h2
