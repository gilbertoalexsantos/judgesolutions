//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1030

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 1e4 + 10;

int _left[MAX], _right[MAX];

void kill(int pos) {
  _right[_left[pos]] = _right[pos];
  _left[_right[pos]] = _left[pos];
}

int main() {
  int nc, cases = 1; scanf("%d", &nc);
  while (nc--) {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      _right[i] = (i+1) % n;
      _left[i] = i == 0 ? n-1 : i-1;
    }
    int qtDead = 0, pos = n-1;
    for (int qtDead = 0; qtDead+1 < n; qtDead++) {
      for (int i = 0; i < k; i++) {
        pos = _right[pos];
      }
      kill(pos);
    }
    int ans = _right[pos] + 1;
    printf("Case %d: %d\n", cases++, ans);
  }
}
