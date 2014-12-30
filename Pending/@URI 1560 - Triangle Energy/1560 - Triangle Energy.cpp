//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1560
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int WHITE = 0, BLACK = 1;

class BIT {
  private:
    vector<int> b;
    int n;

    int lsone(int p) { return p & -p; }

  public:
    BIT(int size) {
      n = size+1;
      b.assign(n,0);
    }

    void update(int pos, int value) {
      for(; pos < n; pos += lsone(pos))
        b[pos] += value;
    }

    int query(int pos) {
      int ret = 0;
      for(; pos > 0; pos -= lsone(pos))
        ret += b[pos];
      return ret;
    }

    void clear(int qt) {
      n = qt+1;
      memset(&b[0], 0, qt * sizeof(int));
    }
};

struct POINT {
  int x, y;
  bool color;

  POINT(int x, int y, int color) : x(x), y(y), color(color) { }
  POINT() : x(0), y(0), color(WHITE) {}

  POINT operator- (POINT a) const { return POINT(x - a.x,y - a.y, a.color); }
  bool operator== (POINT a) const {
    return a.x == x && a.y == y && a.color == color;
  }
};

inline int det(POINT a, POINT b) { return a.x * b.y - a.y * b.x; }
inline int ccw(POINT a, POINT b, POINT c) { return det(a - b,c - b); }

int n, m;
vector<POINT> white, black, ff1, ff2, geral;
POINT flag1, flag2;

void find_points(POINT p_1, POINT p_2) {
  ff1.clear();
  ff2.clear();
  ff1.reserve(black.size() + white.size());
  ff2.reserve(black.size() + white.size());

  // Black points
  for(int z = 0; z < black.size(); z++) {
    POINT g = black[z];
    if(g == p_1 || g == p_2) continue;
    if(ccw(p_1,p_2,g) > 0) {
      ff1.push_back(g);
      ff2.push_back(g);
    }
  }

  // White points
  for(int z = 0; z < white.size(); z++) {
    POINT g = white[z];
    if(ccw(p_1,p_2,g) > 0) {
      ff1.push_back(g);
      ff2.push_back(g);
    }
  }

}

inline bool cmp1(POINT a, POINT b) { return ccw(a,flag1,b) < 0; }
inline bool cmp2(POINT a, POINT b) { return ccw(a,flag2,b) < 0; }

int solve() {
  int ret = 0;
  BIT bit(n+m);
  for(int i = 0; i+2 < black.size(); i++) {
    POINT p_1 = black[i];
    flag1 = p_1;
    for(int j = i+1; j < black.size(); j++) {
      POINT p_2 = black[j];
      flag2 = p_2;

      find_points(p_1,p_2);

      if(ff1.empty())
        continue;

      sort(ff1.begin(),ff1.end(),cmp1);
      sort(ff2.begin(),ff2.end(),cmp2);
      bit.clear(ff2.size());

      int processed_white = 0;
      for(int a = 0; a < ff1.size(); a++) {
        int b = lower_bound(ff2.begin(),ff2.end(),ff1[a],cmp2) - ff2.begin();
        if(ff1[a].color == BLACK) {
          int q = processed_white - bit.query(b);
          ret += q*q;
        }
        else {
          processed_white++;
          bit.update(b+1,1);
        }
      }

    }
  }

  return ret;
}

int main() {
  while(scanf("%d %d",&n,&m) != EOF) {
    black.assign(n,POINT());
    white.assign(m,POINT());
    geral.assign(n+m,POINT());
    for(int i = 0; i < n; i++) {
      POINT p; scanf("%d %d",&p.x,&p.y);
      p.color = BLACK;
      black[i] = p;
      geral[i] = p;
    }
    for(int i = 0; i < m; i++) {
      POINT p; scanf("%d %d",&p.x,&p.y);
      p.color = WHITE;
      white[i] = p;
      geral[i+n] = p;
    }
    int ans = solve();
    printf("%d\n",ans);
  }
}
