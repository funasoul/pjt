/*
 * Last modified: Sat, 16 Mar 2013 03:20:08 +0900
 */
#include <stdio.h>
#include <unistd.h>
#include "mycommon.h"

int main2(int argc, char* argv[])
{
  char* r;

  printf("1問目: expected aaa\n");
  r = mystrsubst("aaaaa", "aa", "a");
  printf("    Your answer %s\n\n", r);
  free(r);

  printf("2問目: expected aaaaaaaaaa\n");
  r = mystrsubst("aaaaa", "a", "aa");
  printf("    Your answer %s\n\n", r);
  free(r);

  printf("3問目: expected babanban\n");
  r = mystrsubst("banana", "na", "ban");
  printf("    Your answer %s\n\n", r);
  free(r);

  printf("4問目: expected banaa\n");
  r = mystrsubst("banana", "nan", "na");
  printf("    Your answer %s\n\n", r);
  free(r);

  printf("5問目: expected abcdefg\n");
  r = mystrsubst("abcdef", "def", "defg");
  printf("    Your answer %s\n\n", r);
  free(r);

  printf("6問目: expected abcxy\n");
  r = mystrsubst("abcdef", "def", "xy");
  printf("    Your answer %s\n\n", r);
  free(r);

  printf("7問目: expected aaef\n");
  r = mystrsubst("abcdef", "bcd", "a");
  printf("    Your answer %s\n\n", r);
  free(r);

  printf("8問目: expected aef\n");
  r = mystrsubst("abcdef", "bcd", "");
  printf("    Your answer %s\n\n", r);
  free(r);

  printf("9問目: expected abcdef\n");
  r = mystrsubst("abcdef", "", "xyz");
  printf("    Your answer %s\n", r);
  free(r);

  return 0;
}

int main(int argc, char** argv)
{
  int ret = main2(argc, argv);
  char buf[256];
  /* sprintf(buf, "leaks %d | tail -1", getpid()); */
  sprintf(buf, "leaks %d", getpid());
  system(buf);
  return ret;
}
