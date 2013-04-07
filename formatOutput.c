/*
 * Last modified: Sun, 07 Apr 2013 20:39:56 +0900
 */
#include <stdio.h>
#include "mycommon.h"

char* formatOutput(char* pbuf, char* obuf) {
  char *h, *t;
  char msg[] = " 0 leaks ";
  chomp(pbuf);
  h = mystrcontain(pbuf, msg);
  if (h == NULL) return NULL;
  *h = '\0';
  t = h + mystrlen(msg);
  *(t-1) = '\0';
  sprintf(obuf, "%s %s%s%s %s", pbuf, GREEN, h+1, DEFAULT, t);
  return obuf;
}
