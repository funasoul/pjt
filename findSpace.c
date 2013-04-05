/*
 * Last modified: Fri, 05 Apr 2013 21:54:54 +0900
 */
#include <stdio.h>

char* findSpace(char *name) {
  char *p;
  p = name;
  while (*name != ' ') {
    if (*name == '\0') return NULL;
    name++;
  }
  return name;
}
