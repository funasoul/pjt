/*
 * Last modified: Fri, 15 Mar 2013 23:39:23 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int main(int argc, char* argv[])
{
  int r;

  printf("1問目: expected 0\n");
  r = mystrncmp("abc", "abc", 3);
  printf("    Your answer %d\n\n", r);

  printf("2問目: expected 1\n");
  r = mystrncmp("zyy", "zwy", 2);
  printf("    Your answer %d\n\n", r);

  printf("3問目: expected -1\n");
  r = mystrncmp("ab", "aba", 3);
  printf("    Your answer %d\n\n", r);

  printf("4問目: expected 1\n");
  r = mystrncmp("abc", "ab", 3);
  printf("    Your answer %d\n\n", r);

  printf("5問目: expected -1\n");
  r = mystrncmp("", "abc", 3);
  printf("    Your answer %d\n\n", r);

  printf("6問目: expected 1\n");
  r = mystrncmp("abc", "", 3);
  printf("    Your answer %d\n\n", r);

  printf("7問目: expected 1\n");
  r = mystrncmp("abc", "", 4);
  printf("    Your answer %d\n\n", r);

  printf("8問目: expected -1\n");
  r = mystrncmp("", "abc", 4);
  printf("    Your answer %d\n", r);

  return 0;
}
