hepsi: derle calistir

derle:
	g++ -I ./include -c ./src/CircularDoublyLinkedList.cpp -o ./lib/CircularDoublyLinkedList.o
	g++ -I ./include -c ./src/Node.cpp -o ./lib/Node.o
	g++ -I ./include ./src/main.cpp -o ./bin/main ./lib/CircularDoublyLinkedList.o ./lib/Node.o

calistir:
	./bin/main.exe