//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1890

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    int c, d; scanf("%d %d", &c, &d);
    if (!c && !d) {
      puts("0");
      continue;
    }
    int ans = 1;
    while (c--) ans *= 26;
    while (d--) ans *= 10;
    printf("%d\n", ans);
  }
}
