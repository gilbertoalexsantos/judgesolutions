//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1886

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1e3;

int n, m;
vector<int> adj[MAX_N];
int match[MAX_N], visited[MAX_N];
vector<int> gu, gv;

void init() {
  gu.clear();
  gv.clear();
  for (int i = 0; i < n; i++)
    adj[i].clear();
}

void constructBipartiteGroups() {
  int color[n];
  memset(color, -1, sizeof color);

  queue<int> qe; qe.push(0);
  color[0] = false;
  while (!qe.empty()) {
    int u = qe.front(); qe.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (color[v] != -1) {
        continue;
      }
      qe.push(v);
      color[v] = !color[u];
    }
  }

  for (int i = 0; i < n; i++) {
    if (color[i])
      gu.push_back(i);
    else
      gv.push_back(i);
  }
}

int augmentPath(int u) {
  if (visited[u])
    return 0;
  visited[u] = true;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (match[v] == -1 || augmentPath(match[v])) {
      match[v] = u;
      return 1;
    }
  }
  return 0;
}

int MCBM() {
  int ret = 0;
  memset(match, -1, sizeof match);
  for (int i = 0; i < gu.size(); i++) {
    memset(visited, false, sizeof visited);
    ret += augmentPath(gu[i]);
  }
  return ret;
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    
    init();
    for (int i = 0; i < m; i++) {
      int u, v; scanf("%d %d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    constructBipartiteGroups();
    
    int qtEdgeMarked = MCBM();
    int qtVMarked = qtEdgeMarked * 2;
    printf("%d\n", qtEdgeMarked + (n - qtVMarked));
  }
}
