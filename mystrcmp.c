/*
 * Last modified: Sat, 16 Mar 2013 00:18:27 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int min(int, int);

int mystrcmp(const char* s1, const char* s2) {
  int l1, l2;
  int i;
  l1 = mystrlen(s1);
  l2 = mystrlen(s2);

  for (i = 0; i < min(l1, l2); i++) {
    if (*(s1+i) == *(s2+i)) {
      continue;
    } else {
      if (*(s1+i) - *(s2+i) > 0) {
        return 1;
      } else {
        return -1;
      }
    }
  }
  if (l1 < l2) {
    return -1;
  } else if (l1 > l2) {
    return 1;
  }
  return 0;
}

int min(int a, int b) {
  return a < b ? a : b;
}

/*
int main(int argc, char const* argv[])
{
  printf("( 1) %2d\n", mystrcmp("hoge", "hog"));
  printf("(-1) %2d\n", mystrcmp("hoge", "hogee"));
  printf("( 0) %2d\n", mystrcmp("hoge", "hoge"));
  printf("( 1) %2d\n", mystrcmp("hoge", "aoge"));
  printf("(-1) %2d\n", mystrcmp("hoge", "iog"));
  return 0;
}
*/
