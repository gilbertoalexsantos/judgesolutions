//Author: Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/LITE/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

struct PAIR {
  int on, off;

  PAIR() { on = off = 0; }
  PAIR(int on, int off) { this->on = on, this->off = off; }
  PAIR operator+(PAIR x) { return PAIR(on+x.on,off+x.off); }

};

const int MAX_RANGE = 100005;
const int LIGHT = 0, RANGE = 1;

class ST {
  private:
    PAIR st[MAX_RANGE * 4];
    bool flag[MAX_RANGE * 4];
    int n;

    inline int left(int p) { return p << 1; }
    inline int right(int p) { return (p << 1) + 1; }
    inline int mid(int x, int y) { return (x+y) >> 1; }

    void build(int p, int l, int r) {
      if(l == r)
        st[p] = PAIR(0,1);
      else {
        build(left(p),l,mid(l,r));
        build(right(p),mid(l,r)+1,r);
        st[p] = st[left(p)] + st[right(p)];
      }
    }

    void propagate(int p, int l, int r) {
      if(flag[p]) {
        swap(st[p].on,st[p].off);
        if(l != r) {
          flag[left(p)] = !flag[left(p)];
          flag[right(p)] = !flag[right(p)];
        }
        flag[p] = 0;
      }
    }

    PAIR update(int p, int l, int r, int i, int j, bool up=false) {
      propagate(p,l,r);
      if(i > r || j < l)
        return PAIR();
      if(i <= l && j >= r) {
        if(up)
          flag[p] = !flag[p];
        propagate(p,l,r);
        return st[p];
      }
      PAIR p1 = update(left(p),l,mid(l,r),i,j,up);
      PAIR p2 = update(right(p),mid(l,r)+1,r,i,j,up);
      st[p] = st[left(p)] + st[right(p)];
      return p1 + p2;
    }

  public:
    ST(int size) {
      n = size;
      for(int i = 0; i <= n*4; i++) {
        st[i] = PAIR();
        flag[i] = false;
      }
      build(1,0,n);
    }

    int range(int i, int j)  { return update(1,0,n,i,j).on; }
    void update(int i, int j) { update(1,0,n,i,j,true); }

};

int n, m;

int main() {
  scanf("%d %d",&n,&m);
  ST st(n);
  for(int i = 0; i < m; i++) {
    int p, left, right;
    scanf("%d %d %d",&p,&left,&right);
    left--, right--;
    if(p == LIGHT)
      st.update(left,right);
    else
      printf("%d\n",st.range(left,right));
  }
}
