#include <stdlib.h>



typedef struct node{
  char *name;
  void *adjacent;
}*Node;

Node createNode(char* name, void *adjacent){
  Node newnode = malloc(sizeof(struct node));
  newnode -> name = name;
  newnode -> adjacent = adjacent;
  return newnode;
}

void rmNode(Node n){
  free(n);
}

