#ifndef __mycommon__
#define __mycommon__
#include <stdlib.h>

#define false 0
#define true 1

#define DEBUG 0

#define PREORDER 0
#define INORDER 1
#define POSTORDER 2
#define UNIQUE_OFFSET 10
#define PREORDER_U  (PREORDER  + UNIQUE_OFFSET)
#define INORDER_U   (INORDER   + UNIQUE_OFFSET)
#define POSTORDER_U (POSTORDER + UNIQUE_OFFSET)

#define PRINT 20
#define GRAPH_PRINT 21
#define DEBUG_PRINT 22
#define REMOVE 23
#define CHECK 24
#define COUNT 25
#define SUBST 26
#define REMOVE_MATCH 27
#define SORT 28
#define START 29
#define END 30

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define DEFAULT "\x1b[39m"
#define UNDER_LINE    "\x1b[4m"
#define BOLD          "\x1b[1m"
#define FONT_DEFAULT "\x1b[0m"

#define DOT_PATH "/opt/local/bin/dot"

int mystrlen(const char*);
char* mystrcpy(char*, const char*);
int mystrcmp(const char*, const char*);
int mystrncmp(const char*, const char*, int);
char* mystrsubst(const char*, const char*, const char*);

typedef struct _BinSTreeNode {
  char* str;
  struct _BinSTreeNode* left;
  struct _BinSTreeNode* right;
  struct _BinSTreeNode* parent;
} BinSTreeNode;

typedef struct _myArgs {
  int action;
  const char* str;
  const char* rstr;
  int delall;
  int num_removed;
  int result;
  int unsort_len;
  int count;
  int is_unique;
  FILE* fp;
  BinSTreeNode** unsortedNodes;
} myArgs;

typedef struct _myOption {
  int print_order;
  int do_subst;
  char* sub_match;
  char* sub_replace;
  int do_remove;
  char* rm_match;
  int rm_delall;
  int is_unique;
  int is_verbose;
  int is_subst_first;
  int is_help;
  int is_graphviz;
} myOption;

BinSTreeNode* createNode(const char *);
void addNode(BinSTreeNode*, BinSTreeNode*);
void setNodeAsLeft(BinSTreeNode*, BinSTreeNode*);
void setNodeAsRight(BinSTreeNode*, BinSTreeNode*);
void unlinkParent(BinSTreeNode*);
void setNodeAsOrphan(BinSTreeNode*);
void deleteNode(BinSTreeNode*);
void printTree(BinSTreeNode*, int);
void debug_printTree(BinSTreeNode*, int);
void checkPrint(BinSTreeNode*);
BinSTreeNode* preorder(BinSTreeNode*, myArgs*);
BinSTreeNode* inorder(BinSTreeNode*, myArgs*);
BinSTreeNode* postorder(BinSTreeNode*, myArgs*);
BinSTreeNode* getMinNode(BinSTreeNode*);
BinSTreeNode* getMaxNode(BinSTreeNode*);
void doNode(BinSTreeNode*, myArgs*);
int substString(BinSTreeNode*, const char*, const char*);
void sortBinSTree(BinSTreeNode*);
void removeNode(BinSTreeNode*, const char*, int);
void clearBinSTree(BinSTreeNode*);
int checkSorted(BinSTreeNode*);
int checkSortedWithArgs(BinSTreeNode*, myArgs*);
int isLeft(BinSTreeNode*, BinSTreeNode*);
int isLeftChild(BinSTreeNode*, BinSTreeNode*);
int isRightChild(BinSTreeNode*, BinSTreeNode*);
void replaceNode(BinSTreeNode*, BinSTreeNode*);
void sortBinSTree(BinSTreeNode*);
int getNodeNum(BinSTreeNode*);
myArgs* create_myArgs_forCheck(BinSTreeNode*);
void free_myArgs(myArgs*);
void free_unsortedNodes(myArgs*);
void createSBML(BinSTreeNode*);
int visualizeGraph(BinSTreeNode*, const char*, myOption*);
int parseOption(int argc, char* argv[], myOption*);
BinSTreeNode* readNode(FILE*, BinSTreeNode*);
void chomp(char*);
char* findSpace(char*);
myOption* create_myOption(void);
void free_myOption(myOption*);
void free_myObjects(BinSTreeNode*, myOption*);
void usage(char*);
char* getFirstString(char*);
char* getSecondString(char*);
char* getStringBetweenSlash(char*, int);
int ismynumber(char*);
int isUnique(BinSTreeNode*);
void removeSort(BinSTreeNode*);
char* mystrcontain(char*, char*);
char* formatOutput(char*, char*);
int hasGraphviz(void);
void verbosePrint(BinSTreeNode*, myOption*, int);

#endif
