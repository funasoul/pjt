/*
 * Last modified: Sat, 16 Mar 2013 00:29:08 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int mystrlen(const char* s) {
  int i;
  int r = 0;
  for (i = 0; s[i] != '\0' ; i++) {
    r++;
  }
  return r;
}
