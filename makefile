all: function.o main.o systema.o laba

function.o: function.cpp
	g++ -c -o function.o function.cpp

main.o: main.cpp	
	g++ -c -o main.o main.cpp

systema.o: systema.cpp
	g++ -c -o systema.o systema.cpp

laba: function.o main.o systema.o
	g++ function.o main.o systema.o laba