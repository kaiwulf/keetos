OBJECTS = keetos.o ticket.o ui.o
HEADERS = keetos.h ticket.h ui.h

prog3: $(OBJECTS) main.o
	g++ $^ -o bin/keetos 

%.o: %.cpp $(HEADERS)
	g++ --std=c++17 -c $< -o $@

clean:
	rm -f *.o