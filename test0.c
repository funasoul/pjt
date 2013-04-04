/*
 * Last modified: Fri, 22 Mar 2013 03:25:29 +0900
 */
#include <stdio.h>
#include <unistd.h>
#include "mycommon.h"

#define SIZE 10

int main2(int argc, char* argv[])
{
  int i;
  char *tst[] = {"F", "B", "G", "A", "D", "C", "E", "I", "H", "B"};
  /* char *tst[] = {"F", "B", "G", "A", "D", "C", "E", "I", "B"}; */
  char ans1[] = "F B A B D C E G I H";
  char ans2[] = "A B B C D E F G H I";
  char ans3[] = "B A C E D B H I G F";
  /* char *tst[] = {"dog", "cat", "ponta", "banana", "donna", "cow", "blue", "fool", "akira"}; */
  /* char ans2[] = "akira banana blue cat cow dog donna fool ponta"; */
  BinSTreeNode* node[SIZE];
  BinSTreeNode *r;
  for (i = 0; i < SIZE; i++) {
    node[i] = createNode(tst[i]); 
    if (i == 0) {
      r = node[0];
    } else {
      addNode(r, node[i]);
    }
  }
  /* Print */
  printf("Expected: [%d] %s\n", SIZE, ans1);
  printf("Your ans: [%s%d%s] ", CYAN, getNodeNum(r), DEFAULT);
  printTree(r, PREORDER);
  printf("Expected: [%d] %s\n", SIZE, ans2);
  printf("Your ans: [%s%d%s] ", CYAN, getNodeNum(r), DEFAULT);
  printTree(r, INORDER);
  printf("Expected: [%d] %s\n", SIZE, ans3);
  printf("Your ans: [%s%d%s] ", CYAN, getNodeNum(r), DEFAULT);
  printTree(r, POSTORDER);
  /* substString(r, "F", "Z"); */
  /* substString(r, "na", "zz"); */
  /* printTree(r, INORDER); */
  /* checkPrint(r); */
  printf("Num = [%s%d%s]\n", CYAN, getNodeNum(r), DEFAULT);

  /* Subst */
  /*
  debug_printTree(r, PREORDER);
  substString(r, "H", "B");
  printTree(r, INORDER);
  checkPrint(r);
  printTree(r, PREORDER);
  printf("Num = [%s%d%s]\n", CYAN, getNodeNum(r), DEFAULT);
  debug_printTree(r, PREORDER);
  */

  /* Remove */
  removeNode(r, "B", true);
  printTree(r, PREORDER);
  printTree(r, INORDER);
  /* debug_printTree(r, PREORDER); */
  checkPrint(r);
  printf("Num = [%s%d%s]\n", CYAN, getNodeNum(r), DEFAULT);

  clearBinSTree(r);
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
