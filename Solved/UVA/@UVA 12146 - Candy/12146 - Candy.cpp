//Author:   Gilberto A. dos Santos
//Website:  https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3298
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n, m;

int main() {
  while (scanf("%d %d", &n, &m) && n+m) {
    int g[n][m];
    int lines[max(n, m)], sum[max(n, m)];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        scanf("%d", &g[i][j]);

    for (int i = 0; i < n; i++) {
      int ma = -1;
      memset(sum, -1, sizeof sum);
      for (int j = m-1; j >= 0; j--) {
        int v = g[i][j];
        if (j == m-1 || j == m-2)
          sum[j] = v;
        else if (j == m-3)
          sum[j] = v + sum[m-1];
        else
          sum[j] = max(v + sum[j+2], v + sum[j+3]);
        ma = max(ma, sum[j]);
      }
      lines[i] = ma;
    }

    int ans = 0;
    memset(sum, -1, sizeof sum);
    for (int i = n-1; i >= 0; i--) {
      int v = lines[i];
      if (i == n-1 || i == n-2)
        sum[i] = v;
      else if (i == n-3)
        sum[i] = v + sum[n-1];
      else
        sum[i] = max(v + sum[i+2], v + sum[i+3]);
      ans = max(ans, sum[i]);
    }

    printf("%d\n", ans);
  }
}
