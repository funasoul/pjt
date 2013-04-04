/*
 * Last modified: Sat, 16 Mar 2013 02:55:00 +0900
 */
#include <stdio.h>
#include "mycommon.h"

char* mystrcpy(char* d, const char* s) {
  while(*s != '\0') {
    *d = *s;
    s++;
    d++;
  }
  *d = '\0';
  return d;
}
