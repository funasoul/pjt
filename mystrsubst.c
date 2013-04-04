/*
 * Last modified: Sat, 16 Mar 2013 02:54:31 +0900
 */
#include <stdio.h>
#include "mycommon.h"

char* mystrsubst(const char* word, const char* s1, const char* s2) {
  int i, j, k = 0;
  char new[256] = {'\0'};
  char *p = new;
  int len;

  len = mystrlen(s1);
  if (len == 0) {
    p = (char*)malloc(sizeof(char)*(mystrlen(word+1)));
    mystrcpy(p, word);
    return p;
  }
  for (i = 0; i < mystrlen(word); i++) {
    if(mystrncmp(word+i, s1, len) == 0) {
      for(j = 0; j < mystrlen(s2); j++) {
        new[k] = s2[j];
        k++;
      }
      i += (len - 1);
    } else {
      new[k] = word[i];
      k++;
    }
  }
  p = (char*)malloc(sizeof(char)*(mystrlen(new)+1));
  mystrcpy(p, new);
  return p;
}
