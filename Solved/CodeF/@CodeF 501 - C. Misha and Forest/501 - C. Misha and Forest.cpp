//Author: Gilberto A. dos Santos
//Website: http://codeforces.com/contest/501/problem/C

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

const int MAX = 1e6;

struct vert {
  int degree, sum;
};

int main() {
  int qtEdge = 0, n;
  scanf("%d",&n);
  vert verts[n];
  stack<int> st;
  for (int i = 0; i < n; i++) {
    scanf("%d %d",&verts[i].degree, &verts[i].sum);
    if (verts[i].degree == 1) {
      st.push(i);
    }
    qtEdge += verts[i].degree;
  }
  
  printf("%d\n", qtEdge / 2);
  while (!st.empty()) {
    int u = st.top(); st.pop();
    if (!verts[u].degree) {
      continue;
    }
    int v = verts[u].sum;
    
    printf("%d %d\n",u, v);

    verts[u].degree--;
    verts[v].degree--;
    verts[v].sum ^= u;

    if (verts[v].degree == 1) {
      st.push(v);
    }
  }
}
