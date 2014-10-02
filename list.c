#include <stdlib.h>


typedef struct link{
  void *data;
  struct link *next;
}*Link;

typedef struct list{
  Link first;
  Link last;
}*List;

List createList(){
  List newList = malloc(sizeof(struct list));
  newList -> first = NULL;
  newList -> last = NULL;
  return newList;
}

void append(List l, void* data){
  Link newLink = malloc(sizeof(struct link));
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

void prepend(List l, void *data){
  Link newLink = malloc(sizeof(struct link));
  newLink -> data = data;
  newLink -> next = l -> first;
  l -> first = newLink;
  if(l -> last == NULL){
    l -> last = newLink;
  }
}

void *read(List l, int index){
  if (index < 0){
    return NULL;
  }
  if (l -> first == NULL){
    return NULL;
  }
  Link node = l -> first;
  for (int i = 0; i < index; ++i){
    if (node -> next == NULL){
      return NULL;
    }
    node = node -> next;
  }
  return node -> data;
}

void rmLink(List l, int index){
  if (l -> first == l -> last  && index == 0){
    if (l -> first != NULL){
      free(l -> first);
      l -> first = NULL;
      l -> last = NULL;
    }
    return;
  }
  Link node = l -> first;
  for (int i = 0; i < index - 1; ++i){
    if (node -> next == NULL){
      return;
    }
    node = node -> next;
  }
  node -> next = node -> next -> next;
  if (node -> next == NULL){
    l -> last = node;
  }
}






