//Author: Gilberto A. dos Santos
//Website: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=655&page=show_problem&problem=4964

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int MAX_N, MAX_D;
int prices[2000];
int memo[2001][21][10];

inline int value(int cents) {
  return cents >= 5 ? 10 - cents : -cents;
}

int dp(int n, int d, int cents) {
  if (d < 0)
    return 0x3f3f3f3f;
  if (n == MAX_N)
    return value(cents);
  if (memo[n][d][cents] != 0x7f7f7f7f)
    return memo[n][d][cents];
  return memo[n][d][cents] = min(dp(n, d-1, 0) + value(cents),
                                 dp(n+1, d, (cents + prices[n]) % 10));
}

int main() {
  while (scanf("%d %d", &MAX_N, &MAX_D) != EOF) {
    memset(memo, 0x7f, sizeof memo);
    
    int sum = 0;
    for (int i = 0; i < MAX_N; i++) {
      scanf("%d", &prices[i]);
      sum += prices[i];
    }

    int ans = dp(0, MAX_D, 0);
    printf("%d\n", sum + ans);
  }
}
