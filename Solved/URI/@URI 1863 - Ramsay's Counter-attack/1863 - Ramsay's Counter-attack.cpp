//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1863

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

// ====== SEG 2d ======
struct Sty {
  int l, r, v, flag;
  bool marked;
  Sty() {}
  Sty(int l, int r, int v): l(l), r(r), v(v) {
    marked = true;
    flag = 0;
  }
};

struct Stx {
  int l, r;
  vector<Sty> sty;
  Stx() {}
  Stx(int l, int r): l(l), r(r) {}
};

struct Segtree2d {
  int n, m;  
  vector<Stx> stx;
  
  double log2(int p) { return log(p) / log(2.0); }
  inline int sizeSt(int p) { return (2 * (1 << (int)ceil(log2(p))))+1; }

  Segtree2d(int n, int m) {
    this->n = n;
    this->m = m;
    stx.resize(sizeSt(n));
    buildX(0, 0, n-1);
  }
  
  int buildY(int px, int py, int ly, int ry) {
    Sty &sty = stx[px].sty[py] = Sty(ly, ry, 0);
    if (ly == ry) {
      if (stx[px].l == stx[px].r)
        return 0;
      else
        return stx[px*2+1].sty[py].v + stx[px*2+2].sty[py].v;
    } else {
      int my = (ly+ry) >> 1;
      int yl = buildY(px, py*2+1, ly, my);
      int yr = buildY(px, py*2+2, my+1, ry);
      return sty.v = yl + yr;
    }
  }

  void buildX(int px, int lx, int rx) {
    Stx &no = stx[px] = Stx(lx, rx);
    if(lx != rx) {
      int mx = (lx+rx) >> 1;
      buildX(2*px+1, lx, mx);
      buildX(2*px+2, mx+1, rx);
    }
    no.sty.resize(sizeSt(m));
    buildY(px, 0, 0, m-1);
  }

  void updateY(int px, int py, int y, int v) {
    Sty &sty = stx[px].sty[py];
    if (sty.l > y || sty.r < y)
      return;
    if (sty.l == sty.r) {
      if (stx[px].l == stx[px].r)
        sty.v = v;
      else
        sty.v = max(stx[2*px+1].sty[py].v, stx[2*px+2].sty[py].v);
      return;
    }
    updateY(px, 2*py+1, y, v);
    updateY(px, 2*py+2, y, v);
    sty.v = max(stx[px].sty[2*py+1].v, stx[px].sty[2*py+2].v);
  }

  void updateX(int px, int x, int y, int v) {
    Stx &no = stx[px];
    if (no.l > x || no.r < x)
      return;
    if (no.l != no.r) {
      updateX(2*px+1, x, y, v);
      updateX(2*px+2, x, y, v);
    }
    updateY(px, 0, y, v);
  }

  void markY(int px, int py, int y, bool marked) {
    Sty &sty = stx[px].sty[py];
    if (sty.l > y || sty.r < y)
      return;
    if (sty.l == sty.r) {
      if (stx[px].l == stx[px].r) {
        sty.marked = marked;
        if (sty.marked)
          sty.v = sty.flag;
        else
          sty.flag = sty.v, sty.v = 0;
      }
      else
        sty.v = max(stx[2*px+1].sty[py].v, stx[2*px+2].sty[py].v);
      return;
    }
    markY(px, 2*py+1, y, marked);
    markY(px, 2*py+2, y, marked);
    sty.v = max(stx[px].sty[2*py+1].v, stx[px].sty[2*py+2].v);
  }
  
  void markX(int px, int x, int y, bool marked) {
    Stx &no = stx[px];
    if (no.l > x || no.r < x)
      return;
    if (no.l != no.r) {
      markX(2*px+1, x, y, marked);
      markX(2*px+2, x, y, marked);
    }
    markY(px, 0, y, marked);
  }

  int queryY(int px, int py, int ly, int ry) {
    Sty &sty = stx[px].sty[py];
    if (sty.l > ry || sty.r < ly)
      return 0;
    if (sty.l >= ly && sty.r <= ry)
      return sty.v;
    int yl = queryY(px, 2*py+1, ly, ry);
    int yr = queryY(px, 2*py+2, ly, ry);
    return max(yl, yr);
  }

  int queryX(int px, int lx, int rx, int ly, int ry) {
    Stx &no = stx[px];
    if (no.l > rx || no.r < lx)
      return 0;
    if (no.l >= lx && no.r <= rx)
      return queryY(px, 0, ly, ry);
    int xl = queryX(2*px+1, lx, rx, ly, ry);
    int xr = queryX(2*px+2, lx, rx, ly, ry);
    return max(xl, xr);
  }

  void update(int x, int y, int v) { updateX(0, x, y, v); }
  void mark(int x, int y, bool marked) { markX(0, x, y, marked); }
  int query(int xi, int yi, int xf, int yf) { return queryX(0, xi, xf, yi, yf); }

};
// ========= Seg ed ========

const int MAX = 50005;
const int RANGE = 400;
const int MAX_RANGE = RANGE*2;

struct point {
  int x, y;
  point() {}
  point(int x, int y) : x(x), y(y) {}
};

int n, m;
vector<int> adj[MAX];
Segtree2d st(MAX_RANGE+1, MAX_RANGE+1);
point points[MAX];
int subTreeSize[MAX], degree[MAX], leave[MAX];

void markSubTree(int u, int p, bool marked) {
  st.mark(points[u].x, points[u].y, marked);
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != p)
      markSubTree(v, u, marked);
  }
}

int getQt(int x, int y) {
  if (x == MAX_RANGE || y == MAX_RANGE)
    return 0;
  int xi = x+1, yi = y+1;
  int xf = MAX_RANGE, yf = MAX_RANGE;
  return st.query(xi, yi, xf, yf);
}

void dfs(int u, int p=-1) {
  subTreeSize[u] = 1;
  int hasChild = 0;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != p) {
      hasChild = 1;
      dfs(v, u);
      subTreeSize[u] += subTreeSize[v];
    }
  }
  if (!hasChild)
    leave[u] = 1;
}

void dp(int u, int p=-1) {
  if (leave[u]) {
    st.update(points[u].x, points[u].y, 1);
    return;
  }

  // Getting subtree with maximum size
  int indMaxSubTree = -1, maxSubTreeSize = -1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != p && subTreeSize[v] > maxSubTreeSize)
      indMaxSubTree = i, maxSubTreeSize = subTreeSize[v];
  }

  // First getting leaves
  int ret = -1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p || i == indMaxSubTree)
      continue;
    dp(v, u);
    ret = max(ret, 1 + getQt(points[u].x, points[u].y));
    markSubTree(v, u, false);
  }

  dp(adj[u][indMaxSubTree], u);
  ret = max(ret, 1 + getQt(points[u].x, points[u].y));

  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != p && i != indMaxSubTree)
      markSubTree(v, u, true);
  }

  st.update(points[u].x, points[u].y, ret);
}

int solve() {
  if (m == 0)
    return 1;
  vector<int> qe;
  for (int i = 0; i < n; i++)
    if (!degree[i])
      qe.push_back(i);
  int ans = -1;
  for (int i = 0; i < qe.size(); i++) {
    dp(qe[i]);
    ans = max(ans, st.query(0, 0, MAX_RANGE, MAX_RANGE));
    markSubTree(qe[i], -1, false);
  }
  return ans;
}

int main() {
  memset(subTreeSize, -1, sizeof subTreeSize);
  memset(degree, 0, sizeof degree);
  memset(leave, 0, sizeof leave);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x, y; scanf("%d %d", &x, &y);
    points[i] = point(x+RANGE, y+RANGE);
  }
  for (int i = 0; i < m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    u--, v--;
    adj[v].push_back(u);
    degree[u]++;
  }
  for (int i = 0; i < n; i++) {
    if (subTreeSize[i] == -1)
      dfs(i);
  }
  int ans = solve();
  printf("%d\n", ans);
}
