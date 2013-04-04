/*
 * Last modified: Sat, 16 Mar 2013 00:29:47 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int mystrncmp(const char *s1, const char *s2, int n) {
  int i;

  for (i = 0; i < n; i++) {
    if (*s1 != *s2) {
      if ((*s1 - *s2) > 0) {
        return 1;
      } else {
        return -1;
      }
    }
    if (*s1 == '\0') return -1;
    if (*s2 == '\0') return 1;
    s1++;
    s2++;
  }
  return 0;
}
