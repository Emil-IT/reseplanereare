#ifndef LIST_H
#define LIST_H

typedef struct list* List;

List createList();

void append(List l, void *data);

void prepend(List l, void *data);

int find(List list, void *data);

void *read(List l, int index);

int listSize(List l);

void rmLink(List l, int index);

void rmList(List l);


#endif



