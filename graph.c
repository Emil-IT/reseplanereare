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
  free(n);
}

