//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1460

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 505;

int grid[MAX][MAX];
int n, m, l, h;

/*
  LowerBound: first not less than
  UpperBound: first greater than
 */
int getBound(int i, int v, bool isRow, bool isLowerBound) {
  int lo = 0, hi = isRow ? m-1 : n-1;
  while (lo <= hi) {
    int mid = (lo+hi)/2;
    int g = isRow ? grid[i][mid] : grid[mid][i];
    int cmp = isLowerBound ? g < v : g <= v;
    if (cmp)
      lo = mid+1;
    else
      hi = mid-1;
  }
  return hi+1;
}

int solve() {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int topLeftC = getBound(i, l, true, true);
    int topRightC = getBound(i, h, true, false) - 1;
    if (topLeftC >= m || topRightC < topLeftC)
      continue;

    while (topRightC >= topLeftC) {
      int rowSize = topRightC - topLeftC;
      if (rowSize+1 <= ans)
        break;
      
      if (i + rowSize >= n) {
        topRightC--;
        continue;
      }

      int bottomRightValue = grid[i+rowSize][topRightC];
      if (bottomRightValue <= h)
        ans = max(ans, rowSize+1);

      topRightC--;
    }
  }
  return ans;
}

int main() {
  while (scanf("%d %d", &n, &m) && n+m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        scanf("%d", &grid[i][j]);

    int q; scanf("%d", &q);
    while (q--) {
      scanf("%d %d", &l, &h);
      printf("%d\n", solve());
     }
    puts("-");
  }
}
