/*
 * Last modified: Mon, 08 Apr 2013 21:33:05 +0900
 */
#include <stdio.h>
#include <unistd.h>
#include "mycommon.h"

int main2(int argc, char* argv[])
{
  int i, rest_args;
  FILE *fp;
  char *myname = argv[0];
  BinSTreeNode *r = NULL;
  myOption *opt = create_myOption();
  myOption *opt_head = opt;

  /* Option handling */
  rest_args = parseOption(--argc, ++argv, opt);
  if (rest_args == -1 || opt->is_help) {
    usage(myname);
    free_myObjects(r, opt);
    return -1;
  }
  /* Create tree from input */
  argv += argc - rest_args;
  if (rest_args == 0) {  /* read from command line */
    printf("Please input node name, and end with [EOF].\n");
    fp = stdin;
    r = readNode(fp, r);
  } else {               /* read from files */
    for (i = 0; i < rest_args; i++) {
      fp = fopen(argv[i], "r");
      if (fp == NULL) {
        fprintf(stderr, "Can't open input file [%s]\n", argv[i]);
        free_myObjects(r, opt);
        return -1;
      }
      r = readNode(fp, r);
      fclose(fp);
    }
  }
  /* Here we go! */
  verbosePrint(r, opt_head, START);
  /* is unique print */
  if (opt_head->is_unique) {
    opt_head->print_order += UNIQUE_OFFSET;
  }
  /* get option from queue and execute */
  while (opt != NULL) {
    if (opt->do_subst) {
      substString(r, opt->sub_match, opt->sub_replace);
      verbosePrint(r, opt_head, SUBST);
    } else if (opt->do_remove) {
      removeNode(r, opt->rm_match, opt->rm_delall);
      verbosePrint(r, opt_head, REMOVE_MATCH);
    }
    opt = opt->next;
  }
  /* Print Tree */
  verbosePrint(r, opt_head, END);
  free_myObjects(r, opt_head);

  return 0;
}

int main(int argc, char** argv)
{
  FILE *pp;
  int ret = main2(argc, argv);
  char buf[256], pbuf[256], obuf[256];
  /*
  sprintf(buf, "leaks %d", getpid());
  system(buf);
  */
  sprintf(buf, "leaks %d | grep ' leaks for '", getpid());
  pp = popen(buf, "r");
  fgets(pbuf, sizeof(pbuf), pp);
  if (formatOutput(pbuf, obuf) != NULL) {
    printf("%s\n", obuf);
  } else {
    printf("%s%s%s\n", RED, pbuf, DEFAULT);
  }
  return ret;
}
