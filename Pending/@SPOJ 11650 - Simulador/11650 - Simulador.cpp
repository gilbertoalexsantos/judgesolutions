//Author: Gilberto A. dos Santos
//Website:  http://br.spoj.com/problems/SIMUL09/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;

const int MAX = 3005;
const char INVERSION = 'I';

int n, m, cnt;
int inv[MAX][2];
set<int> mark;

int pos(int u) {
  for (int i = cnt-1; i >= 0; i--) {
    if (u >= inv[i][0] && u <= inv[i][1]) {
      u = inv[i][0] + inv[i][1] - u;
    }
  }
  return u;
}

ll sumAp(int a, int b) {
  if (a > b) {
    swap(a, b);
  }
  return (a + b) * (b - a + 1LL) / 2LL;
}

ll sum(int a, int b) {
  return 1;
}

int main() {
  cnt = 0;
  
  scanf("%d %d\n", &n, &m);
  for(int i = 0; i < m; i++) {
    char op; int a, b;
    scanf("%c %d %d\n", &op, &a, &b);
    if(op == INVERSION) {
      inv[cnt][0] = a;
      inv[cnt++][1] = b;
      
      mark.insert(a-1);
      mark.insert(b);
    } else {
      printf("%lld\n",sum(a,b));
    }
  }

  printf("%d\n", pos(7));
}
