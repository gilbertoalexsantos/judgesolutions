//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1200
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

string order;
char word[20];

struct node {
  char v;
  node *left, *right;

  node(int v) {
    this->v = v;
    left = right = NULL;
  }
};

class BinarySearchTree {
  private:
    node *root;

    void insert(char v, node *&n) {
      if(n == NULL)
        n = new node(v);
      else
        insert(v,v < n->v ? n->left : n->right);
    }

    bool search(char v, node *n) {
      if(n == NULL)
        return false;
      else if(n->v == v)
        return true;
      else
        return search(v,v < n->v ? n->left : n->right);
    }

    void preorder(node *n) {
      if(n == NULL)
        return;
      order += n->v;
      preorder(n->left);
      preorder(n->right);
    }

    void inorder(node *n) {
      if(n == NULL)
        return;
      inorder(n->left);
      order += n->v;
      inorder(n->right);
    }
    
    void posorder(node *n) {
      if(n == NULL)
        return;
      posorder(n->left);
      posorder(n->right);
      order += n->v;
    }

  public:
    BinarySearchTree() {
      root = NULL;
    }

    void insert(char v) {
      insert(v,root); 
    }

    bool search(char v) {
      return search(v, root);
    }

    void preorder() {
      preorder(root);
    }

    void inorder() {
      inorder(root);
    }

    void posorder() {
      posorder(root);
    }
};

int main() { 
  BinarySearchTree bst;
  while(fgets(word,20,stdin) && word[0] != '\n') {
    if(word[1] == ' ') {
      if(word[0] == 'I')
        bst.insert(word[2]);
      else
        printf("%c %s\n",word[2],bst.search(word[2]) ? "existe" : "nao existe");
    } else {
      if(word[0] == 'I')
        bst.inorder();
      else if(word[1] == 'R')
        bst.preorder();
      else
        bst.posorder();
      if(!order.empty())
        printf("%c",order[0]);
      for(int i = 1; i < order.size(); i++)
        printf(" %c",order[i]);
      puts("");
      order.clear();
    }
  }
}
