#include "graph.c"
#include <stdlib.h>


int main(int argc, char *argv[])
{
  char *name = "test";
  int adj = 5;
  Node newnode = createNode(name, &adj);
  return 0;
}
