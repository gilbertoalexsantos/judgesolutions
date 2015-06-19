//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1030

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int bt(int n, int k) {
  if (n == 1) {
    return 1;
  } else {
    return ((bt(n-1, k) + k-1) % n) + 1;
  }
}

int main() {
  int nc, cases = 1; scanf("%d", &nc);
  while (nc--) {
    int n, k; scanf("%d %d", &n, &k);
    int ans = bt(n, k);
    printf("Case %d: %d\n", cases++, ans);
  }
}
