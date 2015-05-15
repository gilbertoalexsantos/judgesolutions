//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3390

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int QT_VERT = 1e5 + 5;
const int MAX = 2 * QT_VERT;

typedef long long ll;

struct EDGE {
  int v;
  ll w;

  EDGE(int v, ll w) : v(v), w(w) {}
};

vector<EDGE> adj[QT_VERT];
ll dist[QT_VERT];
int n;

int E[MAX], H[MAX], L[MAX];
int st[4 * MAX];
int idx;

void clear() {
  idx = 0;
  memset(H, -1, sizeof H);
  memset(st, 0, sizeof st);
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    dist[i] = -1;
  }
  dist[0] = 0;
}

void dfs(int u, int depth=0, int parent=-1) {
  H[u] = idx;
  E[idx] = u;
  L[idx++] = depth;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i].v;
    ll w = adj[u][i].w;
    if (v != parent) {
      dist[v] = dist[u] + w;
      dfs(v, depth+1, u);
      E[idx] = u;
      L[idx++] = depth;
    }
  }
}

inline int left(int p) { return p << 1; }
inline int right(int p) { return left(p) + 1; }
inline int mid(int x, int y) { return (x + y) >> 1; }

void buildSeg(int p, int l, int r) {
  if (l == r) {
    st[p] = l;
    return;
  }
  
  buildSeg(left(p), l, mid(l, r));
  buildSeg(right(p), mid(l,r) + 1, r);

  int p1 = st[left(p)], p2 = st[right(p)];
  st[p] = L[p1] < L[p2] ? p1 : p2;
}

int range(int p, int l, int r, int i, int j) {
  if (i > r || j < l) {
    return -1;
  }
  if (i <= l && j >= r) {
    return st[p];
  }
  int p1 = range(left(p), l, mid(l, r), i, j);
  int p2 = range(right(p), mid(l, r) + 1, r, i, j);

  if (p1 == -1 || p2 == -1) {
    return p1 == -1 ? p2 : p1;
  }
  
  return L[p1] < L[p2] ? p1 : p2;
}

int LCA(int l, int r) {
  l = H[l], r = H[r];
  if (l > r) {
    swap(l, r);
  }
  return E[range(1, 0, 2*n - 1, l, r)];
}

ll solve(int l, int r) {
  int lca = LCA(l, r);
  
  return dist[l] + dist[r] - (2 * dist[lca]);
}

int main() {
  while (scanf("%d", &n) && n) {
    clear();
    for (int u = 1; u < n; u++) {
      int v; ll w; scanf("%d %lld", &v, &w);
      adj[u].push_back(EDGE(v, w));
      adj[v].push_back(EDGE(u, w));
    }

    dfs(0);
    buildSeg(1, 0, 2*n - 1);

    int Q; scanf("%d", &Q);
    Q--;
    int l, r; scanf("%d %d", &l, &r);
    ll ans = solve(l, r);
    printf("%lld", ans);
    while (Q--) {
      int l, r; scanf("%d %d", &l, &r);
      ans = solve(l, r);
      printf(" %lld", ans);
    }
    puts("");

  }
}
