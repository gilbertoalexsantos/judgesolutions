//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1069

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

ll fact[14];
int n, l, r;
ll memo[14][14];

void init() {
  fact[0] = 1;
  for (int i = 1; i < 14; i++) {
    fact[i] = i * fact[i - 1];
  }
}

inline ll crn(ll N, ll R) { return fact[N] / (fact[R] * (fact[N - R])); }

void calcMemo() {
  memset(memo, 0, sizeof memo);
  for (int i = 0; i < 14; i++) {
    memo[i][i] = 1;
    for (int j = i+1; j < 14; j++) {
      memo[i][j] = 0;
    }
  }
  
  for (int i = 1; i < 14; i++) {
    for (int j = 1; j < i; j++) {
      for (int z = j-1; z <= i-1; z++) {
        memo[i][j] += memo[z][j-1] * fact[i-z-1] * crn(i-1, z);
      }
    }
  }
}

ll range() {
  ll ret = 0;
  for (int i = l-1; i <= n-1-(r-1); i++) {
    ret += memo[i][l-1] * memo[n-1-i][r-1] * crn(n-1, i);
  }
  return ret;
}

int main() {
  init();
  calcMemo();
  int T; scanf("%d", &T);
  while(T--) {
    scanf("%d %d %d", &n, &l, &r);
    printf("%lld\n", range());
  }
}
