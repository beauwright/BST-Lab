TARGETS = Test_Binary_Search_Tree_Numbers bst
CC = g++
CCFLAGS = -std=c++11 -g
bst: main.cpp BSTInterface.h NodeInterface.h BST.h BST.cpp Node.h Node.cpp
	$(CC) $(CCFLAGS) -o Lab7 main.cpp BST.cpp Node.cpp
