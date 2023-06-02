#include <iostream>

using namespace std;

long long res[35] = {0};

struct TNode {
	int key = 0;
	TNode* pLeft = nullptr;
	TNode* pRight = nullptr;
};

struct BSTree {
	TNode* root = nullptr;
};

void initialize(BSTree** tree) {
	(*tree) = new BSTree;
}

bool isEmpty(BSTree* tree) {
	return !(tree->root);
}

TNode *insert(TNode *node, int value){
	if(node!=NULL){
		if(node->key == value){
			return node;
		}else if(node->key > value){
			node->pLeft = insert(node->pLeft, value);
		}else{
			node->pRight = insert(node->pRight, value);
		}
	}else{
		node = new TNode;
		node->key = value;
	}
	return node;
}

long long calcC(int n, int k) {
	long long tmp = 1;
	for (int i = k + 1; i <= n; i++)
		tmp *= i;
	for (int i = 1; i <= (n - k); i++)
		tmp /= i;
	return tmp;
}

long long solve(int value, TNode* node) {
	if (!node->pLeft && !node->pRight) {
		res[value] = 1;
		return 1;
	}
	long long calc1 = 0, calc2 = 0;
	if (node->pLeft)
		calc1 = solve(node->pLeft->key, node->pLeft);
	if (node->pRight)
		calc2 = solve(node->pRight->key, node->pRight);
	if (!calc1) {
		res[value] = res[node->pRight->key];
		return calc2 + 1;
	}
	else if (!calc2) {
		res[value] = res[node->pLeft->key];
		return calc1 + 1;
	}
	long long cnt = calc1 + calc2 + 1;
	res[value] = calcC(max(calc1, calc2) + 1, min(calc1, calc2)) * res[node->pLeft->key] * res[node->pRight->key];
	return cnt;
}

void deinitialize(TNode* node) {
	if (!node) {
		return;
	}
	deinitialize(node->pLeft);
	deinitialize(node->pRight);
	delete node;
	node = nullptr;
}

int main() {
	BSTree* tree;
	initialize(&tree);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (!i)
			tree->root = insert(tree->root, x);
		else
			insert(tree->root, x);
	}
	solve(tree->root->key, tree->root);
	cout << res[tree->root->key];
	deinitialize(tree->root);
	delete tree;
	tree = nullptr;
	return 0;
}
