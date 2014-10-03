#ifndef GRAPH_H
#define GRAPH_H

typedef struct node *Node;

Node createNode(char* name);

void addAdjacent(Node node, void *adj);

void rmAdjacent(Node node, void *adj);

void rmNode(Node *n);

#endif
