CFLAGS = -std=c++11 -g
shape:	main.o Shapes.o 
	g++ $(CFLAGS) -o shape main.o Shapes.o


main.o:	main.cpp
	g++ $(CFLAGS) -c main.cpp

Shapes.o: Shapes.cpp
	g++ -c $(CFLAGS) Shapes.cpp

clean:
	rm *.o
