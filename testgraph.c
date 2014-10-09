#include <stdlib.h>
#include "graph.h"

struct tuple {
  unsigned int dist;
  struct node *adjNode;
};

int distance(struct node *from, struct node *to){
  int index = findAdjacent(from, to);
  if (index == -1){
    int n = 0;
    while (readAdjacent(from -> adjacent, n) != NULL){
      struct node *adj = readAdjacent(from -> adjacent, n++);
      return (adj -> dist) + distance(adj -> adjNode, to);
    }
  }
  struct node *adj = readAdjacent(from -> adjacent, index);
  return adj -> dist;
  
}

int main()
{
  struct node *alfa = createNode("Alfa");
  struct node *beta = createNode("Beta");
  struct node *gamma = createNode("Gamma");
  struct node *delta = createNode("Delta");
  struct tuple AB = {.dist = 5, .adjNode = beta};
  struct tuple BG = {.dist = 7, .adjNode = gamma};
  struct tuple AD = {.dist = 13, .adjNode = delta};
  struct tuple GD = {.dist = 4, .adjNode = delta};
  addAdjacent(alfa, &AB);
  addAdjacent(beta, &BG);
  addAdjacent(alfa, &AD);
  addAdjacent(gamma, &GD);
  
  
  return 0;
}


