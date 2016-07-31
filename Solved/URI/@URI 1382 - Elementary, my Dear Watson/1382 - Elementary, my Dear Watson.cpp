//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1382

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int main() {
  int t; scanf("%d", &t);
  while (t--) {
    int n; scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
      scanf("%d", &v[i]);

    int pos[n+1];
    for (int i = 0; i < n; i++)
      pos[v[i]] = i;

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == i+1)
        continue;

      int j = pos[i+1];
      pos[v[i]] = j;
      swap(v[i], v[j]);
      ans++;
    }
    printf("%d\n", ans);
  }
}
