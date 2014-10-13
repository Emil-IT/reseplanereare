testlist: list.o testlist.o
	gcc -std=c99 list.o testlist.o -o testlist
testlist.o: testlist.c
	gcc -c -std=c99 testlist.c -o testlist.o
testgraph: list.o graph.o testgraph.o
	gcc list.o graph.o testgraph.o -o testgraph
list.o: list.c
	gcc -c -std=c99 -o list.o list.c
graph.o: graph.c list.o
	gcc -c -std=c99 -o graph.o graph.c
testgraph.o: testgraph.c
	gcc -c -std=c99 -o testgraph.o testgraph.c
clean:
	rm *.o