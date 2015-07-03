//Author: Gilberto A. dos Santos
//Website:

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int L = 0, R = 1;
const int MAX_V = 500005;

unsigned long long n;
int m;
int st[MAX_V];
int tr[MAX_V][2];
int degree[MAX_V];
unsigned long long bl[MAX_V];

void bfs() {
  memset(bl, 0, sizeof bl);
  bl[1] = n;
  queue<int> qe; qe.push(1);

  while (!qe.empty()) {
    int u = qe.front(); qe.pop();
    int lv = tr[u][L], rv = tr[u][R];
    
    if (bl[u] != 0) {
      bool md = bl[u] % 2 != 0;
      unsigned long long dv = bl[u] / 2;
      bl[lv] += dv + (st[u] == L ? md : 0);
      bl[rv] += dv + (st[u] == R ? md : 0);
      st[u] = md ? !st[u] : st[u];
    }

    degree[lv]--;
    degree[rv]--;
    
    if (!degree[lv] && lv) {
      qe.push(lv);
    }    
    if (rv && lv != rv && !degree[rv]) {
      qe.push(rv);
    }
  }
}

void removeFalseRoots() {
  queue<int> qe;
  for (int i = 0; i <= m; i++) {
    if (!degree[i] && i != 1) {
      qe.push(i);
    }
  }

  while (!qe.empty()) {
    int u = qe.front(); qe.pop();
    int lv = tr[u][L], rv = tr[u][R];
    degree[lv]--;
    degree[rv]--;

    if (lv && !degree[lv]) {
      qe.push(lv);
    }

    if (rv && lv != rv && !degree[rv]) {
      qe.push(rv);
    }
  }
}

int main() {
  while (scanf("%llu %d\n", &n, &m) != EOF) {
    memset(degree, 0, sizeof degree);     
    for (int i = 1; i <= m; i++) {
      char c; int u, v;
      scanf("%c %d %d\n", &c, &u, &v);
      st[i] = c == 'L' ? L : R;
      tr[i][L] = u; tr[i][R] = v;
      degree[u]++; degree[v]++;
    }
    removeFalseRoots();
    bfs();
    for (int i = 1; i <= m; i++) {
      printf("%c", st[i] == L ? 'L' : 'R');
    }
    puts("");
  }
}
