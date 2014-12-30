//Author:	Gilberto A. dos Santos
//Website:	http://www.spoj.com/problems/LCA/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_VERT = 1005;
const int MAX_V = 2 * MAX_VERT;
const int INF = 1e9;

vector<int> graph[MAX_VERT];
int E[MAX_V], L[MAX_V], H[MAX_V];
int qt_vert, idx;

class ST {
  private:
    vector<int> st;
    int n;

    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1;}
    int mid(int a, int b) { return (a + b) >> 1; }

    void build(int p, int l, int r, int v[]) {
      if(l == r) {
        st[p] = l;
        return;
      }
      build(left(p),l,mid(l,r),v);
      build(right(p),mid(l,r)+1,r,v);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = L[p1] <= L[p2] ? p1 : p2;
    }

    int query(int p, int l, int r, int i, int j) {
      if(i > r || j < l)
        return -1;
      if(i <= l && j >= r)
        return st[p];
      int p1 = query(left(p),l,mid(l,r),i,j);
      int p2 = query(right(p),mid(l,r)+1,r,i,j);
      if(p1 == -1)
        return p2;
      if(p2 == -1)
        return p1;
      return L[p1] <= L[p2] ? p1 : p2;
    }

  public:
    ST(int vert, int v[]) {
      n = vert*2-1;
      st.assign(n * 4, 0);
      build(1,0,n-1,v);
    }

    int query(int i, int j) { return query(1,0,n-1,i,j); }
};

void clear() {
  for(int i = 0; i < qt_vert; i++)
    graph[i].clear();
  idx = 0;
  memset(E,-1,sizeof E);
  memset(H,-1,sizeof H);
  memset(L,-1,sizeof L);
}

void dfs(int u, int dep=0) {
  H[u] = idx;
  E[idx] = u;
  L[idx++] = dep;
  for(int i = 0; i < graph[u].size(); i++) {
    dfs(graph[u][i],dep+1);
    E[idx] = u;
    L[idx++] = dep;
  }
}

int main() {
  int cases=1, T; scanf("%d",&T);
  while(T--) {
    scanf("%d",&qt_vert);  
    clear();
    for(int i = 0; i < qt_vert; i++) {
      int k; scanf("%d",&k);
      while(k--) {
        int v; scanf("%d",&v);
        graph[i].push_back(v-1);
      }
    }
    printf("Case %d:\n",cases++);
    dfs(0);
    ST st(qt_vert,L);
    int Q; scanf("%d",&Q);
    while(Q--) {
      int u, v; scanf("%d %d",&u,&v);
      u--, v--;
      int hu = H[u], hv = H[v];
      if(hu > hv)
        swap(hu,hv);
      int ind = st.query(hu,hv);
      printf("%d\n",E[ind]+1);
    }
  }
}
