#include "BSTree.h"

BSTree::BSTree(const BSTree& obj) {
	root = deepCopy(obj.root);
}

TNode* BSTree::deepCopy(TNode* tn) {
	if (tn) {
		TNode* t = new TNode;
		t->data = tn->data;
		t->left = deepCopy(tn->left);
		t->right = deepCopy(tn->right);
		return t;
	}
	else
		return NULL;
}

BSTree::~BSTree() {
	removeSubTree(root);
	root = NULL;
}

void BSTree::removeSubTree(TNode* tr) {
	if (tr) {
		if (tr->left)
			removeSubTree(tr->left);
		if (tr->right)
			removeSubTree(tr->right);
		delete tr;
		tr = NULL;
	}
}

void BSTree::preOrder(TNode* tn)const {
	if (tn) {
		cout << tn->data << " ";
		preOrder(tn->left);
		preOrder(tn->right);
	}
}

void BSTree::preOrder()const {
	preOrder(root);
}

void BSTree::inOrder(TNode* tn) const {
	if (tn) {
		inOrder(tn->left);
		cout << tn->data << " ";
		inOrder(tn->right);
	}
}

void BSTree::inOrder()const {
	inOrder(root);
}

void BSTree::postOrder(TNode* tn) const {
	if (tn) {
		postOrder(tn->left);
		postOrder(tn->right);
		cout << tn->data << " ";
	}
}

void BSTree::postOrder()const {
	postOrder(root);
}

bool BSTree::search(int key)const {
	TNode* curr = root;
	while (curr) {
		if (curr->data == key)
			return true;
		else if (curr->data < key)
			curr = curr->left;
		else
			curr = curr->right;
	}
	return false;
}

bool BSTree::insert(int val) {
	TNode* curr = root, * prt = NULL;
	while (curr) {
		if (curr->data == val)
			return false;
		prt = curr;
		if (curr->data < val)
			curr = curr->right;
		else
			curr = curr->left;
	}

	TNode* t = new TNode;
	t->data = val;
	t->left = t->right = NULL;
	if (prt) {
		if (val > prt->data)
			prt->right = t;
		else
			prt->left = t;
	}
	else
		root = t;
	return true;
}

bool BSTree::remove(int val) {
	TNode* t = root, * prt = NULL;
	while (t && t->data != val) {
		prt = t;
		if (val < t->data)
			t = t->left;
		else
			t = t->right;
	}
	if (!t)
		return false;
	else {
		if (t->left && t->right) {
			TNode* r = t->right, * pr = t;
			while (r->left) {
				pr = r;
				r = r->left;
			}
			t->data = r->data;
			t = r;
			prt = pr;
		}
	}
	TNode* ch;
	if (t->left)
		ch = t->left;
	else
		ch = t->right;
	if (!prt)
		root = ch;
	else {
		if (t == prt->left)
			prt->left = ch;
		else
			prt->right = ch;
	}
	delete t;
	t = NULL;
	return true;
}

BSTree* BSTree::operator=(const BSTree& obj) {
	if (root) {
		removeSubTree(root);
	}
	if (obj.root) {
		root = deepCopy(obj.root);
	}
	return this;
}

int BSTree::countNodes() {
	return countNodes(root);
}
int BSTree::countNodes(TNode* tn) {
	if (tn) {
		return 1 + countNodes(tn->left) + countNodes(tn->right);
	}
	else
		return 0;
}

int BSTree::getHeight() {
	return getHeight(root);
}

int BSTree::getHeight(TNode* tn) {
	if (tn) {
		int lH = getHeight(tn->left);
		int rH = getHeight(tn->right);
		if (lH > rH)
			return lH + 1;
		else
			return rH + 1;
	}
	else
		return 0;
}

void BSTree::createBalancedTree(int* arr, int start, int end) {
	if (root) {
		removeSubTree(root);
	}
	root = createBalancedTreeHelper(arr, start, end);
}

TNode* BSTree::createBalancedTreeHelper(int* arr, int start, int end) {
	if (start <= end) {
		int mid = (start + end) / 2;
		TNode* t = new TNode;
		t->data = arr[mid];
		t->left = createBalancedTreeHelper(arr, start, mid - 1);
		t->right = createBalancedTreeHelper(arr, mid + 1, end);
		return t;
	}
	else
		return NULL;
}

int BSTree::findMin() {
	TNode* curr = root;
	
	while (curr)
		curr = curr->left;
	if(curr)
		return curr->data;
}

int BSTree::findMax() {
	TNode* curr = root;
	
	while (curr)
		curr = curr->right;
	if(curr)
		return curr->data;
}

void BSTree::makeEmpty() {
	removeSubTree(root);
}

bool BSTree::recSearch(int key) {
	return recSearch(root, key);
}

bool BSTree::recSearch(TNode* tn, int key) {
	if (tn) {
		if (tn->data == key)
			return true;
		else if (tn->data < key)
			return recSearch(tn->left, key);
		else
			return recSearch(tn->right, key);
	}
	else
		return false;
}

int BSTree::findMinRec() {
	return findMinRec(root);
}

int BSTree::findMinRec(TNode* tn) {
	if (tn) {
		if (tn->left)
			return findMinRec(tn->left);
		else
			return tn->data;
	}
	else
		cout << "Empty.\n";
}

int BSTree::findMaxRec() {
	return findMaxRec(root);
}

int BSTree::findMaxRec(TNode* tn) {
	if (tn) {
		if (tn->right)
			return findMaxRec(tn->right);
		else
			return tn->data;
	}
	else
		cout << "Empty.\n";
}

void BSTree::doubleTree() {
	doubleTree(root);
}

void BSTree::doubleTree(TNode* tn) {
	if (tn) {
		doubleTree(tn->left);
		doubleTree(tn->right);
		TNode* t = new TNode;
		t->data = tn->data;
		t->right = NULL;
		t->left = tn->left;
		tn->left = t;
	}
}

void BSTree::printAllPaths() {
	int path[1000];
	printAllPaths(root, path, 0);
}

void BSTree::printAllPaths(TNode* tn, int* a, int s) {
	if (tn) {
		a[s] = tn->data;
		s++;
		if (!tn->left && !tn->right) {
			for (int i = 0; i < s; i++)
				cout << a[i] << " ";
			cout << endl;
		}
		else {
			printAllPaths(tn->left, a, s);
			printAllPaths(tn->right, a, s);
		}
	}
}

void BSTree::displayInRange(int rollNoStart, int rollNoEnd) {
	displayInRange(root, rollNoStart, rollNoEnd);
}

void BSTree::displayInRange(TNode* tn, int rollNoStart, int rollNoEnd) {
	if (tn) {
		if (tn->data < rollNoStart)
			displayInRange(tn->right, rollNoStart, rollNoEnd);
		else if (tn->data > rollNoEnd)
			displayInRange(tn->left, rollNoStart, rollNoEnd);
		else {
			displayInRange(tn->left, rollNoStart, rollNoEnd);
			cout << tn->data << " ";
			displayInRange(tn->right, rollNoStart, rollNoEnd);
		}
	}
}