/*
 * Last modified: Fri, 05 Apr 2013 02:38:41 +0900
 */
#include <stdio.h>
#include <unistd.h>
#include "mycommon.h"

#define SIZE 10

void remove_test(BinSTreeNode* r) {
  /* Remove */
  removeNode(r, "B", true);
  printTree(r, PREORDER);
  printTree(r, INORDER);
  /* debug_printTree(r, PREORDER); */
  checkPrint(r);
  printf("Num = [%s%d%s]\n", CYAN, getNodeNum(r), DEFAULT);

}

void subst_test(BinSTreeNode* r) {
  /* Subst */
  /* debug_printTree(r, PREORDER); */
  substString(r, "H", "B");
  printTree(r, INORDER);
  checkPrint(r);
  printTree(r, PREORDER);
  printf("Num = [%s%d%s]\n", CYAN, getNodeNum(r), DEFAULT);
  /* debug_printTree(r, PREORDER); */
}

void print_test(BinSTreeNode* r, char* ans1, char* ans2, char* ans3) {
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
  printf("Num = [%s%d%s]\n", CYAN, getNodeNum(r), DEFAULT);
  checkPrint(r);
}

int main2(int argc, char* argv[])
{
  int i;
  /* char *tst[] = {"F", "B", "G", "A", "D", "C", "E", "I", "H", "B"}; */
  /* char *tst[] = {"F", "B", "G", "A", "D", "C", "E", "I", "B"}; */
  char ans1[] = "F B A B D C E G I H";
  char ans2[] = "A B B C D E F G H I";
  char ans3[] = "B A C E D B H I G F";
  char *tst[] = {"dog", "cat", "ponta", "banana", "baz", "cow", "blue", "foo", "mac", "air"};
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
  print_test(r, ans1, ans2, ans3);
  subst_test(r);
  visualizeGraph(r, "out.pdf");
  remove_test(r);
  clearBinSTree(r);

  return 0;
}

int main(int argc, char** argv)
{
  int ret = main2(argc, argv);
  char buf[256];
  sprintf(buf, "leaks %d | tail -1", getpid());
  /* sprintf(buf, "leaks %d", getpid()); */
  system(buf);
  return ret;
}
