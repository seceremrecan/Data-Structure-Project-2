all:derle bagla calistir

derle:
	
	g++ -c -I "./include" ./src/ReadFile.cpp -o ./lib/ReadFile.o
	g++ -c -I "./include" ./src/Binary_Tree.cpp -o ./lib/Binary_Tree.o
	g++ -c -I "./include" ./src/Tissue.cpp -o ./lib/Tissue.o
	g++ -c -I "./include" ./src/Cell.cpp -o ./lib/Cell.o
	g++ -c -I "./include" ./src/Control.cpp -o ./lib/Control.o
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/Organism.cpp -o ./lib/Organism.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/Radix_Sort.cpp -o ./lib/Radix_Sort.o
	g++ -c -I "./include" ./src/System.cpp -o ./lib/System.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o

bagla:
	g++  ./lib/ReadFile.o ./lib/Binary_Tree.o ./lib/Tissue.o ./lib/Cell.o ./lib/Control.o ./lib/Organ.o ./lib/Organism.o ./lib/Queue.o ./lib/Radix_Sort.o ./lib/System.o  ./lib/main.o -o ./bin/program

calistir:
	./bin/program	