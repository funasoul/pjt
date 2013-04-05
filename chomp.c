/*
 * Last modified: Fri, 05 Apr 2013 19:39:59 +0900
 */
#include <stdio.h>

void chomp(char *str) {
  while (*str != '\n' && *str != '\0') {
    str++;
  }
  *str = '\0';
}
