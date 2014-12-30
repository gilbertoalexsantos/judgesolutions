//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4622

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;

const int MAX = 100001;
const char UPDATE = 'B', QUERY = 'Q';

class ST {
  private:
    vi st, flag; 

    inline int left(int p) { return p << 1; }
    inline int right(int p) { return (p << 1) + 1; }
    inline int mid(int x, int y) { return (x + y) >> 1; }

    void propagate(int p, int l, int r) {
      st[p] += (r - l + 1) * flag[p];
      if(l != r) {
        flag[left(p)] += flag[p];
        flag[right(p)] += flag[p];
      }
      flag[p] = 0;
    }

    int update(int p, int l, int r, int i, int j, int v) {
      propagate(p,l,r);
      if(i > r || j < l)
        return 0;
      if(i <= l && j >= r) {
        flag[p] += v;
        propagate(p,l,r);
        return st[p];
      }
      int p1 = update(left(p),l,mid(l,r),i,j,v);
      int p2 = update(right(p),mid(l,r)+1,r,i,j,v);
      st[p] = st[left(p)] + st[right(p)];
      return p1 + p2;
    }

  public:
    ST() {
      st.assign(MAX*4,0);
      flag.assign(MAX*4,0);
    }

    void clear() {
      st.assign(MAX*4,0);
      flag.assign(MAX*4,0);
    }

    int query(int l, int r) { return update(1,0,MAX-1,l,r,0); }
    int query(int l) { return update(1,0,MAX-1,l,l,0); }
    int update(int l, int r, int v) { return update(1,0,MAX-1,l,r,v); }
};

int main() {
  int t;
  ST st;
  while(scanf("%d\n",&t) && t) {
    st.clear();
    while(t--) {
      char c; scanf("%c",&c); 
      if(c == UPDATE) {
        int L, R, v; scanf("%d %d %d\n",&L,&R,&v);
        st.update(L-1,R-1,v);
      } else {
        int Q; scanf("%d\n",&Q);  
        printf("%d\n",st.query(Q-1));
      }
    }
  }
}
