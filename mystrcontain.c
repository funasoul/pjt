/*
 * Last modified: Sun, 07 Apr 2013 20:24:14 +0900
 */
#include <stdio.h>
#include "mycommon.h"

char* mystrcontain(char* s, char* m) {
  int count = 0;
  char* mark;
  char* start = m;
  while (*s != '\0' && *m != '\0') {
    if (*s != *m) {
      count = 0;
      m = start;
      s++;
    } else {
      if (count == 0) mark = s;
      count++;
      s++; m++;
    }
  }
  if (mystrlen(start) == count) return mark;
  return NULL;
}

/*
int main(int argc, char const* argv[])
{
  char s[] = "Process 70345: 0 leaks for 0 total leaked bytes.";
  char m[] = " 0 leaks ";
  char *p;
  printf("[%s]\n", s);
  printf("[%s]\n", m);
  if ((p = mystrcontain(s, m)) != NULL) {
    printf("Found!! [%s]\n", p);
  } else {
    printf("Not found...\n");
  }
  return 0;
}
*/
