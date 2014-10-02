#include "list.c"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
  List testlist = createList();
  int testvalue = 5;
  prepend(testlist, &testvalue);
  int *r = read(testlist, 0);
  printf("%d\n", *r);
  return 0;
}




