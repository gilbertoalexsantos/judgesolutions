//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1636

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int v[1000005];

// A B | A B A B A B A B
// A B | A B A B A B A

int main() {
  int n;
  v[1] = 3, v[2] = 1;
  while (scanf("%d", &n) && n) {
    for (int i = 3; i <= n; i += 2)
      v[i] = i + 2;

    if (n % 2 == 0) {
      v[n] = n-2, v[n-1] = n;
      for (int i = n-2; i >= 4; i -= 2)
        v[i] = i - 2;
    } else {
      v[n] = n-1;
      for (int i = n-1; i >= 4; i -= 2)
        v[i] = i-2;
    }

    printf("%d", v[1]);
    for (int i = 2; i <= n; i++)
      printf(" %d", v[i]);
    puts("");
  }
}
