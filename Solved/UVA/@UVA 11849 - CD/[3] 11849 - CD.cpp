//Author:	Gilberto A. dos Santos

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct No {
	int key, priority, child;
	No *left, *right;

	No(int n, int r) { 
		key = n;
		priority = r;
		child = 0;
		left = NULL;
		right = NULL;
	}

	No(int n, int rr, No *l, No *r) {
		key = n;
		priority = rr;
		child = 0;
		left = l;
		right = r;
	}
};

int getCh(No *node);
void augmentCh(No *node);
void updCh(No *node);
void inOrder(No *node);
void split(int n, No *root, No *&l, No *&r);
void merge(No *&root, No *l, No *r);
No *unite(No *l, No *r);
void insert(No *&root, No* *node);
void insert(int n, No *&node);
void remove(int n, No *&node);
No *find(int n, No *node);

int n, m;

int main() {
	while(scanf("%d %d",&n, &m) && n+m) {
		No *treap = NULL;
		int ans = 0;
		while(n--) {
			int t;
			scanf("%d",&t);
			insert(t,treap);
		}
		while(m--) {
			int t;
			scanf("%d",&t);
			if(find(t,treap)) ans++;
		}
		printf("%d\n",ans);
	}
}

int getCh(No *node) { return node ? node->child : 0; }

void augmentCh(No *node) { if(node) node->child = 1 + getCh(node->left) + getCh(node->right); }

void updCh(No *node) { 
	if(node) {
		augmentCh(node->left);
		augmentCh(node->right);
		augmentCh(node);
	}
}

void inOrder(No *node) {
	if(!node) return;
	inOrder(node->left);
	cout << node->key << " ";
	inOrder(node->right);
}

void split(int n, No *root, No *&l, No *&r) {
	if(!root) l = r = NULL;
	else if(n < root->key) {
		split(n,root->left,l,root->left);
		r = root;
	} else {
		split(n,root->right,root->right,r);
		l = root;
	}
	updCh(root);
}

void merge(No *&root, No *l, No *r) {
	if(!l || !r) root = l ? l : r;
	else if(l->priority < r->priority) {
		merge(r->left,l,r->left);
		root = r;
	}
	else {
		merge(l->right,l->right,r);
		root = l;
	}
	updCh(root);
}

No *unite(No *l, No *r) {
	if(!l || !r) return !l ? r : l;
	
	if(l->priority < r->priority) swap(r,l);

	No *ll, *rr;
	split(l->key,r,ll,rr);
	l->left = unite(l->left,ll);
	l->right = unite(l->right,rr);

	return l;
}

void insert(No *&root, No *node) {
	if(!root) root = node;
	else if(node->priority > root->priority) {
		split(node->key,root,node->left,node->right);
		root = node;
	} else (node->key < root->key) ? insert(root->left,node) : insert(root->right,node);
	updCh(root);
}

void insert(int n, No *&node) { 
	No *temp = new No(n,rand());
	insert(node,temp); 
}

void remove(int n, No *&node) {
	if(!node) return;
	if(n != node->key) (n < node->key) ? remove(n,node->left) : remove(n,node->right);
	else merge(node,node->left,node->right);
	updCh(node);
}

No *find(int n, No *node) {
	if(!node) return NULL;
	else {
		if(n < node->key) return find(n,node->left);
		else if(n > node->key) return find(n,node->right);
		else return node;
	}
}
