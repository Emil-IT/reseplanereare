#include <stdlib.h>
#include "list.h"


typedef struct node {
  char *name;
  struct list *adjacent;
}*Node;

Node createNode(char* name){
  Node newnode = malloc(sizeof(struct node));
  newnode -> name = name;
  newnode -> adjacent = createList();
  return newnode;
}

void addAdjacent(Node node, void *adj){
  append(node -> adjacent, adj);
}

void rmAdjacent(Node node, void *adj){
  int index = find(node -> adjacent, adj);
  if (index >= 0) rmLink(node -> adjacent, index);
}

void rmNode(Node n){
  //TODO:Remove from adjacent list
  free(n);
}

char *getName(Node node){
  return node -> name;
}

int findAdjacent(Node nodeA, Node nodeB){
  int index = find(nodeA -> adjacent, nodeB);
  return index;
}
  
Node readAdjacent(Node node, int index){
  Node returnNode = read(node -> adjacent, index);
  return returnNode;
}
