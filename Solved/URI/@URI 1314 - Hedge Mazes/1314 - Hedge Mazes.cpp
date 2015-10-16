//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1314

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> ii;

const int MAX_N = 1e4 + 5;
const int MAX_EDGE = 1e5 + 5;
const int UNVISITED = -1;

int r, c, q;
vector<ii > adj[MAX_N];
int dfs_low[MAX_N], dfs_num[MAX_N], dfs_parent[MAX_N];
int dfsNumberCounter, dfsRoot;
bool is_bridge[MAX_EDGE];
map<int, int> indice;
int cntIndice;
bool visited[MAX_N];

void init() {
  for (int i = 0; i <= r; i++)
    adj[i].clear();
  indice.clear();
  memset(dfs_num, UNVISITED, sizeof dfs_num);
  memset(dfs_parent, 0, sizeof  dfs_parent);
  memset(dfs_low, 0, sizeof dfs_low);
  memset(is_bridge, false, sizeof is_bridge);
  memset(visited, false, sizeof visited);
  cntIndice = 0;
}

void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i].first, e = adj[u][i].second;
    if (dfs_num[v] == UNVISITED) {
      dfs_parent[v] = u;
      articulationPointAndBridge(v);
      if (dfs_low[v] > dfs_num[u])
        is_bridge[e] = true;
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if (v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

void bfs(int x) {
  queue<int> qe;
  qe.push(x);
  visited[x] = true;
  indice[x] = cntIndice;
  while (!qe.empty()) {
    int u = qe.front(); qe.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first, e = adj[u][i].second;
      if (!is_bridge[e] || visited[v])
        continue;
      indice[v] = cntIndice;
      visited[v] = true;
      qe.push(v);
    }
  }
}

int main() {
  while (scanf("%d %d %d", &r, &c, &q) && r+c+q) {
    init();
    for (int i = 0; i < c; i++) {
      int u, v; scanf("%d %d", &u, &v);
      adj[u].push_back(ii(v, i));
      adj[v].push_back(ii(u, i));
    }
    for (int i = 1; i <= r; i++)
      if (dfs_num[i] == UNVISITED) {
        dfsNumberCounter = 0;
        dfsRoot = i;
        articulationPointAndBridge(i);
      }
    for (int i = 1; i <= r; i++)
      if (!visited[i]) {
        bfs(i);
        cntIndice++;
      }
    for (int i = 0; i < q; i++) {
      int u, v; scanf("%d %d", &u, &v);
      int ind1 = indice[u], ind2 = indice[v];
      printf("%c\n", ind1 == ind2 ? 'Y' : 'N');
    }
    puts("-");
  }
}
