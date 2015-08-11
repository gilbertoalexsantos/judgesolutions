//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1092

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int m[600][600], memo[600][600];
int qtRow, qtCol;

int main() {
  int qt = 0;
  while (scanf("%d %d", &qtRow, &qtCol) && qtRow+qtCol) {
    for (int i = 0; i < qtRow; i++)
      for (int j = 0; j < qtCol; j++)
        scanf("%d", &m[i][j]);

    int ans = 1;
    for (int i = 0; i < qtRow; i++) {
      memo[i][0] = 1;
      for (int j = 1; j < qtCol; j++) {
        memo[i][j] = m[i][j] > m[i][j-1] ? 1+memo[i][j-1] : 1;
        ans = max(ans, memo[i][j]);
      }
    }

    for (int base = 1; base <= qtCol; base++) {
      int height[qtCol];
      for (int j = 0; j < qtCol; j++)
        height[j] = memo[0][j] >= base;
      for (int i = 1; i < qtRow; i++) {
        for (int j = base-1; j < qtCol; j++) {
          if (memo[i][j] < base) {
            height[j] = 0;
          } else if (m[i-1][j] >= m[i][j-(base-1)]) {
            height[j] = 1;
          } else {
            height[j]++;
          }
          ans = max(ans, height[j] * base);
        }
      }
    }

    printf("%d\n", ans);
  }
}
