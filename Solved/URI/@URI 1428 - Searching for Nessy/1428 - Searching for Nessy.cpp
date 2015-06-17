//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/pt/problems/view/1467

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int main() {
  int t; scanf("%d", &t);
  while (t--) {
    int n, m; scanf("%d %d", &n, &m);
    n -= 2, m -= 2;
    int ans = ((n / 3) + (n % 3 != 0)) * ((m / 3) + (m % 3 != 0));
    printf("%d\n", ans);
  }
}
