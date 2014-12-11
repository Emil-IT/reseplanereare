#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
  List testlist = createList();
  int testvalue1 = 5;
  int testvalue2 = 3;
  prepend(testlist, &testvalue1);
  append(testlist, &testvalue2);
  printf("%d%d\n", *(int*)(read(testlist, 0)), *(int*)(read(testlist, 1)));
  rmLink(testlist, 0);
  printf("The size of the list is %d and the first number in the list is: %d\n", listSize(testlist), *(int*)(read(testlist, 0)));
  return 0;
}
