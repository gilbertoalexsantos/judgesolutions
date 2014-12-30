//Author: Gilberto A. dos Santos
//Website:  http://br.spoj.com/problems/SIMUL09/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;

const int MAX = 1005;
const char INVERSION = 'I', SUM = 'S';

int n, m;
int inv[MAX][2];
set<int> counter;

ll sumr(int a, int b) {
  ll ma = min(a,b);
  ll mb = max(a,b);
  return (ma+mb) * (mb-ma+1LL) / 2LL;
}

ll sum(int a, int b) {
  return 1;
}

int main() {
  scanf("%d %d\n",&n,&m);
  for(int i = 0; i < m; i++) {
    char op; int a, b;
    scanf("%c %d %d",&op,&a,&b);
    if(op == INVERSION) {
      inv[m][0] = a; inv[m][1] = b;
      counter.insert(a-1);
      counter.insert(b);
    } else
      printf("%lld\n",sum(a,b));
  }
}
