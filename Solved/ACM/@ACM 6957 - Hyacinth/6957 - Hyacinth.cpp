//Author: Gilberto A. dos Santos
//Website: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=655&page=show_problem&problem=4969

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 10005;

struct NIC {
  int n1, n2;
  bool used[2];

  NIC(int n1, int n2) : n1(n1), n2(n2) { used[0] = used[1] = false; }
  NIC(): n1(-1), n2(-1) { used[0] = used[1] = false; }
};

int n;
vector<int> adj[MAX_V];
bool visited[MAX_V];
NIC nic[MAX_V];

void init() {
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
    nic[i] = NIC();
    visited[i] = false;
  }
}

void bfs() {
  int cnt = 2;
  
  queue<int> qe; qe.push(1);
  nic[1] = NIC(0, 1);
  visited[1] = true;
  
  while (!qe.empty()) {
    int u = qe.front(); qe.pop();

    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (visited[v]) {
        continue;
      }

      if (!nic[u].used[0]) {
        nic[v].n1 = nic[u].n1;
        nic[v].n2 = cnt++;
        nic[u].used[0] = nic[v].used[0] = true;
      } else {
        nic[v].n2 = nic[u].n2;
        nic[v].n1 = cnt++;
        nic[u].used[1] = nic[v].used[1] = true;
      }

      visited[v] = true;
      qe.push(v);
    }
  }
}

int main() {
  while (scanf("%d", &n) != EOF) {
    init();
    for (int i = 0; i+1 < n; i++) {
      int u, v; scanf("%d %d", &u, &v);
      adj[u].push_back(v); adj[v].push_back(u);
    }

    bfs();
    if (n == 2) {
      nic[2].n2 = 1;
    }

    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", nic[i].n1, nic[i].n2);
    }
  }
}
