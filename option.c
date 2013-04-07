/*
 * Last modified: Sun, 07 Apr 2013 21:02:05 +0900
 */
#include <stdio.h>
#include "mycommon.h"

int parseOption(int argc, char* argv[], myOption *opt) {
  char* tmpstr;
  while (*argv != NULL && **argv == '-') {
    if (!mystrcmp(*argv, "-p")) {  /* print */
      argv++; argc--;
      if (*argv == NULL) {
        fprintf(stderr, "\"-p\" option requires 0, 1, or 2 as an argument.\n");
        return -1;
      } else {
        if (!ismynumber(*argv) || atoi(*argv) < 0 || atoi(*argv) > 2) {
          fprintf(stderr, "\"-p\" option requires 0, 1, or 2 as an argument.\n");
          return -1;
        } else {
          opt->print_order = atoi(*argv);
          argv++; argc--;
        }
      }
    } else if (!mystrcmp(*argv, "-s")) { /* substr */
      argv++; argc--;
      opt->do_subst = true;
      opt->sub_match = getFirstString(*argv);
      opt->sub_replace = getSecondString(*argv);
      if (opt->sub_match != NULL && opt->sub_replace != NULL) {
        if(DEBUG) printf("  -s [%s][%s]\n", opt->sub_match, opt->sub_replace);
        argv++; argc--;
      } else {
        fprintf(stderr, "\"-s\" option requires \"/match/replace/\" as an argument.\n");
        return -1;
      }
    } else if (!mystrcmp(*argv, "-r")) { /* remove */
      argv++; argc--;
      opt->do_remove = true;
      if (opt->do_subst) {
        opt->is_subst_first = true;
      }
      opt->rm_match = getFirstString(*argv);
      tmpstr = getSecondString(*argv);
      if (opt->rm_match != NULL && ismynumber(tmpstr)) {
        if (atoi(tmpstr) == 0) {
          opt->rm_delall = false;
        } else {
          opt->rm_delall = true;
        }
        free(tmpstr);
        if(DEBUG) printf("  -r [%s][%d]\n", opt->rm_match, opt->rm_delall);
        argv++; argc--;
      } else {
        free(tmpstr);
        fprintf(stderr, "\"-r\" option requires \"/match/dellall_flag/\" as an argument.\n");
        return -1;
      }
    } else if (!mystrcmp(*argv, "-u")) { /* unique */
      argv++; argc--;
      opt->is_unique = true;
    } else if (!mystrcmp(*argv, "-v")) { /* verbose */
      argv++; argc--;
      opt->is_verbose = true;
      opt->is_graphviz = hasGraphviz();
      if (!opt->is_graphviz) {
        fprintf(stderr, "If you want to visualize PJT, please install graphviz from MacPorts.\n(sudo port install graphviz)\n");
      }
    } else if (!mystrcmp(*argv, "-h")) { /* help */
      argv++; argc--;
      opt->is_help = true;
    } else {
      fprintf(stderr, "Unknown option \"%s\"\n", *argv);
      return -1;
    }
  }
  return argc;
}

char* getStringBetweenSlash(char* str, int num) {
  int i;
  int head = -1, tail = -1, count = 0;
  char* rtn;
  if (str == NULL) return NULL;
  for (i = 0; i < mystrlen(str); i++) {
    if (str[i] == '/') {
      count++;
      if (count == num) {
        head = i;
      } else if (count == num+1) {
        tail = i;
      }
    }
  }
  if (tail - head == 1 || head == -1 || tail == -1) return NULL;
  rtn = (char*)malloc(sizeof(char)*(tail - head));
  for (i = 0; i < tail-head-1; i++) {
    rtn[i] = str[head+1+i];
  }
  rtn[i] = '\0';
  return rtn;
}

char* getFirstString(char* str) {
  return getStringBetweenSlash(str, 1);
}

char* getSecondString(char* str) {
  return getStringBetweenSlash(str, 2);
}

