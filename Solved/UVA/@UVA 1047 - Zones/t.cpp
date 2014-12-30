//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3488

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 30;

typedef vector<int> vi;

int qt_tower, qt_build;
int range_tower[MAX];
vector<vi> common(10);
vi ans;
int cust;

void init() {
  ans.clear();
  cust = -1;
  for(int i = 0; i < 10; i++)
    common[i].clear();
}

int getSum(int mask) {
  int ret = 0;
  for(int i = 0; i < qt_tower; i++)
    if(1 << i & mask)
      ret += range_tower[i];
  for(int i = 0; i < 10; i++) {
    int qt_equal = 0;
    for(int j = 0; j+1 < common[i].size(); j++) {
      int c = common[i][j];
      if((1 << (c-1)) & mask)
        qt_equal++;
    }
    if(qt_equal >= 2)
      ret -= (qt_equal - 1) * common[i][common[i].size()-1];
  }
  return ret;
}

void backtrack(int mask=0, int last=0) {
  if(__builtin_popcount(mask) == qt_build) {
    int s = getSum(mask);
    if(cust < s) {
      ans.clear();
      cust = s;
      for(int i = 0; i < qt_tower; i++) {
        if((1 << i) & mask)
          ans.push_back(i+1);
      }
    }
    return;
  }

  for(int i = last; i < qt_tower; i++) {
    if(mask & (1 << i))
      continue;
    backtrack(mask | (1 << i),i);
  }
}

int main() {
  int cases = 1;
  while(scanf("%d %d",&qt_tower,&qt_build) && qt_tower+qt_build) {
    init();
    for(int i = 0; i < qt_tower; i++)
      scanf("%d",&range_tower[i]);
    int inter; scanf("%d",&inter);
    for(int c = 0; c < inter; c++) {
      int qt; scanf("%d",&qt);
      for(int i = 0; i < qt; i++) {
        int x; scanf("%d",&x);
        common[c].push_back(x);
      }
      int x; scanf("%d",&x);
      common[c].push_back(x);
    }
    backtrack();
    printf("Case Number  %d\n",cases++);
    printf("Number of Customers: %d\n",cust);
    printf("Locations recommended:");
    for(int i = 0; i < ans.size(); i++)
      printf(" %d",ans[i]);
    puts("");
    puts("");
  }
}
