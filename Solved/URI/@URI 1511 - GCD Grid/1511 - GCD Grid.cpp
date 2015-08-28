//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1511

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 2001;

struct Sty {
  int l, r, v;
  Sty() {}
  Sty(int l, int r, int v): l(l), r(r), v(v) {}
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

  double log2(int p) { return (double)log(p) / log(2.0); }
  int sizeSt(int p) { return (2 * (1 << (int)ceil(log2(p)))); }
  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

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
        return gcd(stx[px*2+1].sty[py].v, stx[px*2+2].sty[py].v);
    } else {
      int my = (ly+ry) >> 1;
      int yl = buildY(px, py*2+1, ly, my);
      int yr = buildY(px, py*2+2, my+1, ry);
      return sty.v = gcd(yl, yr);
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
        sty.v = gcd(stx[2*px+1].sty[py].v, stx[2*px+2].sty[py].v);
      return;
    }
    updateY(px, 2*py+1, y, v);
    updateY(px, 2*py+2, y, v);
    sty.v = gcd(stx[px].sty[2*py+1].v, stx[px].sty[2*py+2].v);
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

  int queryY(int px, int py, int ly, int ry) {
    Sty &sty = stx[px].sty[py];
    if (sty.l > ry || sty.r < ly)
      return 0;
    if (sty.l >= ly && sty.r <= ry)
      return sty.v;
    int yl = queryY(px, 2*py+1, ly, ry);
    int yr = queryY(px, 2*py+2, ly, ry);
    return gcd(yl, yr);
  }

  int queryX(int px, int lx, int rx, int ly, int ry) {
    Stx &no = stx[px];
    if (no.l > rx || no.r < lx)
      return 0;
    if (no.l >= lx && no.r <= rx)
      return queryY(px, 0, ly, ry);
    int xl = queryX(2*px+1, lx, rx, ly, ry);
    int xr = queryX(2*px+2, lx, rx, ly, ry);
    return gcd(xl, xr);
  }

  void update(int x, int y, int v) { updateX(0, x, y, v); }
  int query(int xi, int yi, int xf, int yf) { return queryX(0, xi, xf, yi, yf); }

};

int main() {
  int t, x, y, d;
  char w[15];   
  while (scanf("%d", &t) != EOF) {
    Segtree2d st(MAX_N, MAX_N);
    while (t--) {
      scanf("%s %d %d %d", w, &x, &y, &d);
      int nx = x+y+1000, ny = y-x+1000;
      if (w[0] == 'S') {
        st.update(nx, ny, d);
      } else {
        int xi = max(0, nx - d), yi = max(0, ny - d);
        int xf = min(2000, nx + d), yf = min(2000, ny + d);
        printf("%d\n", st.query(xi, yi, xf, yf));
      }
    }
  }
}
