//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1891

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int FINISHED = 0, BLACK = 1, DORADO = 2;

int a[100002];

void flip(int pos) {
  if (a[pos] == BLACK)
    a[pos] = DORADO;
  else if(a[pos] == DORADO)
    a[pos] = BLACK;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    int n; scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
      char c; scanf("%c", &c);
      a[i] = c == 'B' ? BLACK : DORADO;
    }
    
    a[0] = a[n+1] = FINISHED;
    
    int it = 1;
    vector<int> ans;
    while (it <= n) {
      if (a[it] != DORADO) {
        it++;
        continue;
      }
      ans.push_back(it);
      a[it] = FINISHED;
      flip(it-1);
      flip(it+1);
      it += a[it-1] == DORADO ? -1 : +1;
    }

    if (ans.size() == n) {
      printf("Y\n");
      printf("%d", ans[0]);
      for (int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
      puts("");
    } else {
      printf("N\n");
    }
  }
}
