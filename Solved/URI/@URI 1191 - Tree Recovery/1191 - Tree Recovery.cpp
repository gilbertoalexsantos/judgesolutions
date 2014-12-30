//Author: Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1191

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

const int MAX = 100;

char preorder[MAX], inorder[MAX];
int size;

void postorder(int l, int r, int mypos=0) {
  if(l > r || l < 0 || r > size)
    return;
  if(l == r) {
    printf("%c",inorder[l]);
    return;
  }
  char c = preorder[mypos];
  int mid = -1;
  for(int i = l; i <= r; i++) {
    if(c == inorder[i]) {
      mid = i;
      break;
    }
  }
  int qt_left = mid - l;
  postorder(l,mid-1,mypos+1);
  postorder(mid+1,r,mypos+qt_left+1);
  printf("%c",c);
}

int main() {
  while(scanf("%s %s",preorder,inorder) != EOF) {
    size = strlen(preorder);
    postorder(0,size-1);
    puts("");
  }
}
