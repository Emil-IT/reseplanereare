#ifndef LIST_H
#define LIST_H

typedef struct list* List;

struct list *createList();

void append(struct list *l, void *data);

void prepend(struct list *l, void *data);

int find(struct list *list, void *data);

void *read(struct list *l, int index);

void rmLink(struct list *l, int index);


#endif



