#pragma once
#include <iostream>
using namespace std;

class BSTree;
class TNode {
	friend class BSTree;
	int data;
	TNode* left, * right;
};
class BSTree {
	TNode* root;
	void preOrder(TNode*)const;
	void inOrder(TNode*)const;
	void postOrder(TNode*)const;
	int countNodes(TNode*);
	int getHeight(TNode*);
	TNode* createBalancedTreeHelper(int*, int, int);
	bool recSearch(TNode*, int);
	int findMinRec(TNode*);
	int findMaxRec(TNode*);
	void doubleTree(TNode*);
	void printAllPaths(TNode*, int*, int);
public:
	BSTree() :root(NULL) {};
	BSTree(const BSTree&);
	TNode* deepCopy(TNode*);
	void displayInRange(TNode*, int, int);
	~BSTree();
	void removeSubTree(TNode*);
	void preOrder()const;
	void inOrder()const;
	void postOrder()const;
	bool search(int)const;
	bool insert(int);
	bool remove(int);
	BSTree* operator = (const BSTree&);
	int countNodes();
	int getHeight();
	void createBalancedTree(int*, int, int);
	int findMin();
	int findMax();
	void makeEmpty();
	bool recSearch(int);
	int findMinRec();
	int findMaxRec();
	void doubleTree();
	void printAllPaths();
	void displayInRange(int, int);
};