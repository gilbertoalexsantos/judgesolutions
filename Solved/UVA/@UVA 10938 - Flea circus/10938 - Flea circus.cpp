//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1879

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int QT_VERT = 5005;

vector<int> adj[QT_VERT];
int n;

void clear() {
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
  }
}

vector<int> getPath(int u, int v) {
  vector<int> ret;
  
  queue<int> qe; qe.push(u);
  int dt[n+1]; memset(dt, -1, sizeof dt);
  dt[u] = u;
  
  while (!qe.empty()) {
    int qu = qe.front(); qe.pop();
    for (int i = 0; i < adj[qu].size(); i++) {
      int qv = adj[qu][i];
      if (dt[qv] != -1) {
        continue;
      } else  {
        dt[qv] = qu;

        if (qv == v) {
          stack<int> path;
          while (dt[qv] != qv) {
            path.push(qv);
            qv = dt[qv];
          }
          path.push(u);
          while (!path.empty()) {
            ret.push_back(path.top());
            path.pop();
          }
          return ret;
        }
        
        qe.push(qv);
      }
    }
  }

  return ret;
}

int main() {
  while (scanf("%d", &n) && n) {
    clear();
    
    for (int i = 0; i+1 < n; i++) {
      int u, v; scanf("%d %d", &u, &v);
      adj[u].push_back(v); adj[v].push_back(u);
    }

    int T; scanf("%d", &T);
    while (T--) {
      int l, r; scanf("%d %d", &l, &r);

      if (l == r) {
        printf("The fleas meet at %d.\n", l);
        continue;
      }

      vector<int> path = getPath(l, r);
      if (path.size() % 2 != 0) {
        printf("The fleas meet at %d.\n", path[path.size() / 2]);
      } else {
        int x = path[path.size() / 2], y = path[path.size() / 2 - 1];
        if (x > y) {
          swap(x, y);
        }
        printf("The fleas jump forever between %d and %d.\n", x, y);
      }
    }
  }
}
