//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4830

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_N = (2 * 100000) + 5;
const int INF = 1e9;

int memo[MAX_N][2];
int v[MAX_N];
int diff[MAX_N];
int n, c;

int dp(int pos, bool buying) {
  if (pos == n)
    return 0;

  int &ret = memo[pos][buying];
  if (ret != -1)
    return ret;

  if (buying) {
    ret = max(diff[pos] + dp(pos+1, true),
              dp(pos, false));
  } else {
    ret = max(dp(pos+1, false),
              diff[pos] - c + dp(pos+1, true));
  }
  
  return ret;
}

int main() {
  while (scanf("%d %d", &n, &c) != EOF) {
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    for (int i = 1; i < n; i++)
      diff[i] = v[i] - v[i-1];
    
    for (int i = n-1; i >= 1; i--)
      for (int j = 0; j < 2; j++)
        dp(i, j);
    
    int ans = dp(1, 0);
    printf("%d\n", ans < 0 ? 0 : ans);
  }
}
