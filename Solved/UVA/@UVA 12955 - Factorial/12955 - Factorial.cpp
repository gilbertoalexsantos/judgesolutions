//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4834

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_F = 9;
const int MAX_N = 100005;
const int INF = 1e9;

int fact[MAX_F];
int memo[MAX_F][MAX_N];
int n;

int main() {
  fact[0] = 0;
  fact[1] = 1;
  for (int i = 2; i < MAX_F; i++)
    fact[i] = i * fact[i-1];
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < MAX_F; i++)
      for (int j = 0; j <= n; j++)
        memo[i][j] = INF;
    for (int i = 0; i <= n; i++)
      memo[1][i] = i;
    for (int i = 0; i < MAX_F; i++)
      memo[i][0] = 0;
    for (int i = 2; i < MAX_F; i++) {
      int p = fact[i];
      if (p > n)
        break;
      for (int j = 0; j <= n; j++) {
        if (j - p < 0) {
          memo[i][j] = memo[i-1][j];
          continue;
        }
        memo[i][j] = min(memo[i-1][j], min(1+memo[i-1][j-p], 1+memo[i][j-p]));
      }
    }
    int ans = 1e9;
    for (int i = 1; i < MAX_F; i++)
      if (memo[i][n] != -1)
        ans = min(ans, memo[i][n]);
    printf("%d\n", ans);
  }
}
