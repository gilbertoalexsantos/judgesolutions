//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3673

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 5;

struct node {
  int ma, mi, lazy;

  node() : ma(0), mi(0), lazy(0) {}
};

node st[MAX * 4];
int n;

inline int ll(int p) { return p * 2; }
inline int rr(int p) { return p * 2 + 1; }
inline int mid(int u, int v) { return (u+v)/2; }

void propagate(int p, int l, int r) {
  node &n = st[p];
  if (!n.lazy)
    return;
  if (l != r) {
    node &nl = st[ll(p)], &nr = st[rr(p)];
    nl.ma = nl.mi = nl.lazy = n.lazy;
    nr.ma = nr.mi = nr.lazy = n.lazy;
    n.lazy = 0;
  }
}

int update(int p, int l, int r, int i, int j, int h) {
  if (l > r)
    return 0;
  propagate(p, l, r);
  if (i > r || j < l || h < st[p].mi)
    return 0;
  if (i <= l && j >= r) {
    if (h >= st[p].ma) {
      st[p].ma = st[p].mi = st[p].lazy = h;
      propagate(p, l, r);
      return r - l + 1;
    }
  }
  int left = update(ll(p), l, mid(l,r), i, j, h);
  int right = update(rr(p), mid(l,r)+1, r, i, j, h);
  st[p].ma = max(st[ll(p)].ma, st[rr(p)].ma);
  st[p].mi = min(st[ll(p)].mi, st[rr(p)].mi);
  return left + right;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < MAX*4; i++)
      st[i] = node();
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int l, r, h; scanf("%d %d %d", &l, &r, &h);
      ans += update(1, 1, MAX, l, r-1, h);
    }
    printf("%d\n", ans);
  }
}
