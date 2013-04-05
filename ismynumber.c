/*
 * Last modified: Sat, 06 Apr 2013 05:39:24 +0900
 */
#include <stdio.h>
#include <ctype.h>
#include "mycommon.h"

int ismynumber(char* s) {
  if (s == NULL) return false;
  while (*s != '\0') {
    if (!isdigit(*s)) return false;
    s++;
  }
  return true;
}
