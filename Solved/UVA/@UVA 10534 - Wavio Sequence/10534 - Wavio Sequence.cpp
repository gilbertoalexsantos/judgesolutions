//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1475

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1e4 + 1;
int n;
int v[MAX], vb[MAX], l[MAX];

vector<int> calcLis(int a[]) {
  vector<int> ret(n);
  int lis = 0;
  for (int i = 0; i < n; i++) {
    int p = lower_bound(l, l+lis, a[i]) - l;
    l[p] = a[i];
    ret[i] = p;
    if (p+1 > lis)
      lis = p+1;
  }
  return ret;
}

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0, j = n-1; i < n; i++, j--) {
      scanf("%d", &v[i]);
      vb[j] = v[i];
    }

    int ans = 0;
    vector<int> l1 = calcLis(v), l2 = calcLis(vb);
    for (int i = 0, j = n-1; i < l1.size(); i++, j--)
      ans = max(ans, 2 * min(l1[i], l2[j]) + 1);
    
    printf("%d\n", ans);
  }
}
