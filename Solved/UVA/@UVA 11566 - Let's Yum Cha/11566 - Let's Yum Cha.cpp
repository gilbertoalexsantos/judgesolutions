//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2613

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_N = 25;
const int MAX_SIZE = 1005;
const int MAX_ITEM = 105;

int price[MAX_ITEM], favour[MAX_ITEM];
int memo[MAX_N][MAX_SIZE];
int n, x, t, k;

int main() {
  while(scanf("%d %d %d %d", &n, &x, &t, &k) && n+x+t+k) {
    n++; t = t*n;
    memset(memo, 0, sizeof memo);
    
    int sumPrice = 0;
    for(int i = 0; i < k; i++) {
      scanf("%d", &price[i]);
      int sumFavour = 0;
      for(int j = 0; j < n; j++) {
        int f; scanf("%d", &f);
        sumFavour += f;
      }
      favour[i] = sumFavour;
    }

    int cost = x * n, size = cost;
    while (cost < (int)ceil((double)((size+t)*11)/10.0))
      size--;
    
    for (int i = 0; i < k*2; i++) {
      int p = price[i%k], f = favour[i%k];
      for (int s = size; s >= p; s--)
        for (int j = 1; j <= 2*n; j++)
          memo[j][s] = max(memo[j][s], f + memo[j-1][s-p]);
    }
    
    int ans = memo[2*n][size];
    printf("%.2lf\n", (double)ans / n);
  }
}
