//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=777

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 27;
const int INF = 1e5;

int grid[MAX][MAX];
char grid_c[MAX][MAX];
int r, c;

int main() {
  int t; scanf("%d\n\n", &t);
  while (t--) {
    r = 0;
    while (fgets(grid_c[r], MAX, stdin) && grid_c[r++][0] != '\n');
    r -= grid_c[r-1][0] == '\n' ? 1 : 0;
    c = strlen(grid_c[0]) - 1;

    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        grid[i][j] = grid_c[i][j] == '0' ? -INF : 1;

    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) {
        if (i > 0) grid[i][j] += grid[i-1][j];
        if (j > 0) grid[i][j] += grid[i][j-1];
        if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
      }

    int ans = 0;
    for (int xi = 0; xi < r; xi++)
      for (int yi = 0; yi < c; yi++)
        for (int xf = xi; xf < r; xf++)
          for (int yf = yi; yf < c; yf++) {
            int sum = grid[xf][yf];
            if (xi > 0) sum -= grid[xi-1][yf];
            if (yi > 0) sum -= grid[xf][yi-1];
            if (xi > 0 && yi > 0) sum += grid[xi-1][yi-1];
            ans = max(ans, sum);
          }

    printf("%d\n", ans);
    if (t) puts("");
  }
}
