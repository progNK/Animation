all: main

scene.o: scene.cpp scene.hpp
	g++ -c scene.cpp
figure.o: figure.cpp figure.hpp
	g++ -c figure.cpp
main.o: main.cpp scene.cpp scene.hpp figure.cpp figure.hpp
	g++ -c main.cpp
main: scene.o figure.o main.o
	g++ scene.o figure.o main.o -o main -lfltk
clean:
	rm -rf *.o
	rm -rf main
