//Author: Gilberto A. dos Santos
//Website: http://www.spoj.com/problems/QTREE/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 10000;
const int MAX_LOG = 14;
const int root = 0;

vector<int> adj[MAX_N], costs[MAX_N], indexEdge[MAX_N];
int depth[MAX_N], otherEnd[MAX_N], subTreeSize[MAX_N];
int chainHead[MAX_N], posInBase[MAX_N], chainInd[MAX_N];
int baseArray[MAX_N];
int dpLca[MAX_N][MAX_LOG];
int n, ptr, cn;
int st[MAX_N*4], qt[MAX_N*4];

void init() {
  ptr = cn = 0;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    indexEdge[i].clear();
    costs[i].clear();
    chainHead[i] = -1;
    subTreeSize[i] = 0;
  }
  memset(dpLca, -1, sizeof dpLca);
}

void dfs(int u, int p=-1, int d=0) {
  dpLca[u][0] = p;
  depth[u] = d;
  subTreeSize[u] = 1;
   for (int i = 0; i < adj[u].size(); i++) {
     int v = adj[u][i];
     if (v == p)
       continue;
     otherEnd[indexEdge[u][i]] = v;
     dfs(v, u, d+1);
     subTreeSize[u] += subTreeSize[v];
  }
}

void hld(int u, int cts=-1, int p=-1) {
  if (chainHead[cn] == -1)
    chainHead[cn] = u;
  
  chainInd[u] = cn;
  posInBase[u] = ptr;
  baseArray[ptr++] = cts;

  int ind = -1, maxSize = -1e9;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != p && (ind == -1 || subTreeSize[v] > maxSize))
      ind = i, maxSize = subTreeSize[v];
  }

  if (ind != -1)
    hld(adj[u][ind], costs[u][ind], u);

  for (int i = 0; i < adj[u].size(); i++) {
    if (i != ind && adj[u][i] != p) {
      cn++;
      hld(adj[u][i], costs[u][i], u);
    }
  }
}

void buildLca() {
  for (int j = 1; 1 << j < n; j++)
    for (int i = 0; i < n; i++)
      if (dpLca[i][j-1] != -1)
        dpLca[i][j] = dpLca[dpLca[i][j-1]][j-1];
}

int lca(int u, int v) {
  if (depth[u] < depth[v])
    swap(u, v);
  
  int k;
  for (k = 1; 1 << k <= depth[u]; k++);
  k--;
  
  for (int i = k; i >= 0; i--)
    if (depth[u] - (1 << i) >= depth[v])
      u = dpLca[u][i];
  if (u == v)
    return u;
  for (int i = k; i >= 0; i--)
    if (dpLca[u][i] != -1 && dpLca[u][i] != dpLca[v][i])
      u = dpLca[u][i], v = dpLca[v][i];
  return dpLca[u][0];
}

void buildSegTree(int p, int l, int r) {
  if (l == r-1) {
    st[p] = baseArray[l];
    return;
  }
  int le = p << 1, re = le | 1, mi = (l+r) >> 1;
  buildSegTree(le, l, mi);
  buildSegTree(re, mi, r);
  st[p] = max(st[le], st[re]);
}

void updTree(int p, int l, int r, int u, int v) {
  if (l > u || r <= u)
    return;
  if (l == r-1 && l == u) {
    st[p] = v;
    return;
  }
  int le = p << 1, re = le | 1, mi = (l+r) >> 1;  
  updTree(le, l, mi, u, v);
  updTree(re, mi, r, u, v);
  st[p] = st[le] > st[re] ? st[le] : st[re];
}

void queryTree(int p, int l, int r, int i, int j) {
  if (l >= j || r <= i) {
    qt[p] = -1;
    return;
  }
  if (l >= i && r <= j) {
    qt[p] = st[p];
    return;
  }
  int le = p << 1, re = le | 1, mi = (l+r) >> 1;    
  queryTree(le, l, mi, i, j);
  queryTree(re, mi, r, i, j);
  qt[p] = qt[le] > qt[re] ? qt[le] : qt[re];
}

int queryUp(int u, int v) {
  if (u == v)
    return 0;
  int uchain, vchain = chainInd[v], ans = -1;
  while(1) {
    uchain = chainInd[u];
    if (uchain == vchain) {
      if (u == v)
        break;
      queryTree(1, 0, n, posInBase[v]+1, posInBase[u]+1);
      ans = ans > qt[1] ? ans : qt[1];
      break;
    }
    queryTree(1, 0, n, posInBase[chainHead[uchain]], posInBase[u]+1);
    ans = ans > qt[1] ? ans : qt[1];
    u = dpLca[chainHead[uchain]][0];
  }
  return ans;  
}

int query(int u, int v) {
  int l = lca(u, v);
  int la = queryUp(u, l), lv = queryUp(v, l);
  return la > lv ? la : lv;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    init();
    for (int i = 0; i+1 < n; i++) {
      int u, v, w; scanf("%d %d %d", &u, &v, &w);
      u--, v--;
      indexEdge[u].push_back(i);
      indexEdge[v].push_back(i);
      adj[u].push_back(v);
      adj[v].push_back(u);
      costs[u].push_back(w);
      costs[v].push_back(w);
    }
    
    dfs(root);
    hld(root);
    buildLca();
    buildSegTree(1, 0, n);

    char t[10];
    while (scanf("%s", t) && t[0] != 'D') {
      int u, v; scanf("%d %d", &u, &v);
      if (t[0] == 'Q') {
        printf("%d\n", query(u-1, v-1));
      } else {
        updTree(1, 0, n, posInBase[otherEnd[u-1]], v);
      }
    }
  }
}
