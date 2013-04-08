PROG = pjt
TEST = test
OBJSCOMMON  = formatOutput.o mystrcontain.o removeSort.o unique.o ismynumber.o usage.o myOption.o findSpace.o chomp.o readNode.o option.o visualizeGraph.o myArgs.o myfree.o sortTree.o removeNode.o substString.o isChild.o isLeft.o getNodeNum.o checkSorted.o clearBinSTree.o doNode.o searchNode.o traverseTree.o printTree.o deleteNode.o setNode.o addNode.o createNode.o mystrcmp.o mystrcpy.o mystrlen.o mystrncmp.o mystrsubst.o
OBJST = $(OBJSCOMMON) test.o
OBJSM = $(OBJSCOMMON) main.o
CC = gcc
#CFLAGS = -Wall -O0 -g -I/opt/local/include/graphviz
CFLAGS = -Wall -O0 -g
#LDFLAGS = -L/opt/local/lib -lgvc -lcgraph -lcdt -lm
LDFLAGS = -lm

.PHONY: all
all: $(PROG)
#all: $(TEST)

.SUFFIXES: .o .c
.c.o:
	$(CC) $(CFLAGS) -c $<

$(PROG): $(OBJSM)
	$(CC) -o $@ $^ $(LDFLAGS)

$(TEST): $(OBJST)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean: 
	rm -f $(PROG) $(TEST) $(OBJS) $(OBJST)

.PHONY: tags
tags: 
	ctags -Re *.c *.h
