test: list.o graph.o testgraph.o
	gcc list.o graph.o testgraph.o -o test
list.o: list.c
	gcc -c -std=c99 -o list.o list.c
graph.o: graph.c
	gcc -c -std=c99 -o graph.o graph.c
testgraph.o: testgraph.c
	gcc -c -std=c99 -o testgraph.o testgraph.c