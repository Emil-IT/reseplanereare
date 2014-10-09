#include <stdlib.h>


struct link {
  void *data;
  struct link *next;
};

struct list {
  struct link *first;
  struct link *last;
};

struct list *createList(){
  struct list * newList = malloc(sizeof(struct list));
  newList -> first = NULL;
  newList -> last = NULL;
  return newList;
}

void append(struct list *l, void* data){
  struct link * newLink = malloc(sizeof(struct link));
  newLink -> data = data;
  newLink -> next = NULL;
  if (l -> last == NULL){
    l -> last = newLink;
    l -> first = newLink;
  }
  else{
    l -> last -> next = newLink;
    l -> last = newLink;
  }
}

void prepend(struct list * l, void *data){
  struct link * newLink = malloc(sizeof(struct link));
  newLink -> data = data;
  newLink -> next = l -> first;
  l -> first = newLink;
  if(l -> last == NULL){
    l -> last = newLink;
  }
}

int find(struct list *list, void *data){
  struct link *tmpLink = list -> first;
  int index = 0;
  while (tmpLink -> next != NULL){
    if (tmpLink -> data == data) return index;
    index++;
  }
  return -1;
}

void *read(struct list * l, int index){
  if (index < 0){
    return NULL;
  }
  if (l -> first == NULL){
    return NULL;
  }
  struct link * node = l -> first;
  for (int i = 0; i < index; ++i){
    if (node -> next == NULL){
      return NULL;
    }
    node = node -> next;
  }
  return node -> data;
}

void rmLink(struct list * l, int index){
  if (l -> first == l -> last  && index == 0){
    if (l -> first != NULL){
      free(l -> first);
      l -> first = NULL;
      l -> last = NULL;
    }
    return;
  }
  struct link * node = l -> first;
  for (int i = 0; i < index - 1; ++i){
    if (node -> next == NULL){
      return;
    }
    node = node -> next;
  }
  struct link *tempNode = node -> next;
  node -> next = node -> next -> next;
  free(tempNode);
  if (node -> next == NULL){
    l -> last = node;
  }
}






