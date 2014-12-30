//Author:	Gilberto A. dos Santos

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class SplayTree {
private:
	struct No {
		int key;
		No *left, *right, *parent;

		No(int n, No *p) {
			key = n;
			left = NULL;
			right = NULL;
			parent = p;
		}
	};

	No *root;
	int size;

	void left_rotate(No *node) {
		No *temp = node->right;
		node->right = temp->left;
		if(temp->left) temp->left->parent = node;
		temp->parent = node->parent;
		if(!node->parent) root = temp;
		else if(node == node->parent->left) node->parent->left = temp;
		else node->parent->right = temp;
		temp->left = node;
		node->parent = temp;
	}

	void right_rotate(No *node) {
		No *temp = node->left;
		node->left = temp->right;
		if(temp->right) temp->right->parent = node;
		temp->parent = node->parent;
		if(!node->parent) root = temp;
		else if(node == node->parent->left) node->parent->left = temp;
		else node->parent->right = temp;
		temp->right = node;
		node->parent = temp;
	}

	void splay(No *node) {
		while(node->parent) {
			if(!node->parent->parent) {
				(node->parent->left == node) ? right_rotate(node->parent) : left_rotate(node->parent);
			} else if(node->parent->left == node && node->parent->parent->left == node->parent) {
				right_rotate(node->parent->parent);
				right_rotate(node->parent);
			} else if(node->parent->right == node && node->parent->parent->right == node->parent) {
				left_rotate(node->parent->parent);
				left_rotate(node->parent);
			} else if(node->parent->left == node && node->parent->parent->right == node->parent) {
				right_rotate(node->parent);
				left_rotate(node->parent);
			} else {
				left_rotate(node->parent);
				right_rotate(node->parent);
			}
		}
	}

	No *subtree_min(No *node) {
		while(node->left) node = node->left;
		return node;
	}

	No *subtree_max(No *node) {
		while(node->right) node = node->right;
		return node;
	}

	No *find(int n, No *node) {
		if(!node) return NULL;
		else {
			if(n < node->key) return find(n,node->left);
			else if(n > node->key) return find(n,node->right);
			else {
				splay(node);
				return node;
			}
		}
	}

	void insert(int n, No *&node, No *&p) {
		if(!node) {
			node = new No(n,p);
			splay(node);	
		} else (n < node->key) ? insert(n,node->left,node) : insert(n,node->right,node);
	}

	void replace(No *u, No *v) {
		if(!u->parent) root = v;
		else if(u == u->parent->left) u->parent->left = v;
		else u->parent->right = v;
		if(v) v->parent = u->parent;
	}

	bool remove(int n, No *node) {
		No *u = find(n,root);
		if(!u) return false;

		if(!u->left) replace(u,u->right);
		else if(!u->right) replace(u,u->left);
		else {
			No *v = subtree_min(u->right);
			if(v->parent != u) {
				replace(v,v->right);
				v->right = u->right;
				v->right->parent = v;
			}
			replace(u,v);
			v->left = u->left;
			v->left->parent = v;
		}

		delete u;
		size--;
		return true;
	}

	void inOrder(No *node) {
		if(!node) return;
		inOrder(node->left);
		cout << node->key << " ";
		inOrder(node->right);
	}

public:
	SplayTree() {
		root = NULL;
		size = 0;
	}
	
	void insert(int n) { size++; insert(n, root, root); }
	void remove(int n) { remove(n, root); }
	void inOrder() { inOrder(root); }
	bool find(int n) { return (!size) ? false : find(n,root); }
	int getSize() { return size; }
	bool empty() { return size == 0; }
};

int n, m;

int main() {
	while(scanf("%d %d",&n, &m) && n+m) {
		SplayTree st;
		int ans = 0;
		while(n--) {
			int t;
			scanf("%d",&t);
			st.insert(t);
		}
		while(m--) {
			int t;
			scanf("%d",&t);
			if(st.find(t)) ans++;
		}
		printf("%d\n",ans);
	}
}
