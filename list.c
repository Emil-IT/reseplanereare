#include <stdlib.h>
#include <assert.h>

typedef struct link {
  void *data;
  struct link *next;
} *Link;

typedef struct list {
  Link first;
  Link last;
  int size;
} *List;

List createList(){
  List newList = malloc(sizeof(struct list));
  newList -> first = NULL;
  newList -> last = NULL;
  newList -> size = 0;
  assert(newList != NULL);
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
  l -> size += 1;
  assert(l -> size != 0);
}

void prepend(List l, void *data){
  Link newLink = malloc(sizeof(struct link));
  newLink -> data = data;
  newLink -> next = l -> first;
  l -> first = newLink;
  if(l -> last == NULL){
    l -> last = newLink;
  }
  l -> size += 1;
  assert(l -> size != 0);
}

int find(List list, void *data){
  Link tmpLink = list -> first;
  int index = 0;
  while (tmpLink -> next != NULL){
    if (tmpLink -> data == data) return index;
    index++;
  }
  return -1;
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

void rmLink(List l, int index) {
  if (l -> first == l -> last && index == 0) {
    if (l -> first != NULL) {
      free(l -> first);
      l -> first = NULL;
      l -> last = NULL;
      l -> size = 0;
    }
    return;
  }
  Link node = l -> first;
  if (index == 0){
    l -> first = l -> first -> next;
    free(node);
    l -> size -= 1;
    return;
  }
  for (int i = 0; i < index - 1; ++i){
    if (node -> next == NULL){
      return;
    }
    node = node -> next;
  }
  Link tempNode = node -> next;
  node -> next = node -> next -> next;
  free(tempNode);
  l -> size -= 1;
  if (node -> next == NULL){
    l -> last = node;
  }
}

int listSize(List l){
  return l -> size;
}

void rmList(List l){
  int length = listSize(l);
  for (int i; i < length; i++){
    rmLink(l, i);
  }
  free(l);
}
