typedef struct link{
  void *data;
  struct link *next;
}*Link;

typedef struct list{
  Link first;
  Link last;
}*List;

List createList()

void append(List l, void* data)

void prepend(List l, void *data)

void *read(List l, int index)

void rmLink(List l, int index)






