//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1642

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_LINE = 1000005;
const int MAX_CHAR = 300;

char line[MAX_LINE];
int ns[MAX_LINE];
int qt[MAX_CHAR];
int m, size;

int main() {
  while (scanf("%d\n", &m) && m) {
    fscanf(stdin, "%[^\n]", line);
    size = strlen(line);

    for (int i = 0; i < size; i++)
      ns[i] = (int)line[i];

    memset(qt, 0, sizeof(qt));

    int ans = -1, qtDiff = 1, l = 0, r = 1;
    qt[ns[0]] = 1;
    while (r < size && l <= r) {
      ans = max(ans, r - l);

      if (qt[ns[r]] > 0) {
        qt[ns[r++]]++;  
      } else {
        if (qtDiff < m) {
          qt[ns[r++]]++;
          qtDiff++;
        } else {
          qt[ns[l]]--;
          if (qt[ns[l]] == 0)
            qtDiff--;
          l++;
        }
      }

    }

    ans = max(ans, r - l);

    printf("%d\n", ans);
  }
}

