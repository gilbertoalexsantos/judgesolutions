//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1391

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
using namespace std;

const int MAX_V = 505;
const int MAX_E = 10005;
const int INF = 1e9;

typedef pair<int, int> ii;
typedef set<ii>::iterator IT;

int n, m;
vector<ii> adj[MAX_V];
vector<ii> adj_b[MAX_V];
int dist_optimal[MAX_V];
bool visited[MAX_V];
set<ii> except_edge;
int a, b;

void init() {
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    adj_b[i].clear();
  }
  except_edge.clear();
  memset(visited, false, sizeof(visited));
}

void clear_dist() {
  for (int i = 0; i < MAX_V; i++)
    dist_optimal[i] = INF;
}

int dijkstra_optimal() {
  clear_dist();
  dist_optimal[a] = 0;
  priority_queue<ii> qe; qe.push(ii(0, a));
  while (!qe.empty()) {
    int w = qe.top().first, u = qe.top().second;
    qe.pop();
    if (dist_optimal[u] < w)
      continue;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first, ww = adj[u][i].second;
      if (dist_optimal[u] + ww < dist_optimal[v]) {
        dist_optimal[v] = dist_optimal[u] + ww;
        qe.push(ii(-dist_optimal[v], v));
      }
    }
  }
  return dist_optimal[b] == INF ? -1 : dist_optimal[b];
}

void dfs_remove_edge(int u, int d) {
  visited[u] = true;
  for (int i = 0; i < adj_b[u].size(); i++) {
    int v = adj_b[u][i].first, w = adj_b[u][i].second;
    if (visited[v])
      continue;
    if (dist_optimal[v] + w == d) {
      except_edge.insert(ii(v, u));
      dfs_remove_edge(v, d - w);
    }
  }
}

int dijsktra_suboptimal() {
  clear_dist();
  dist_optimal[a] = 0;
  priority_queue<ii> qe; qe.push(ii(0, a));
  while (!qe.empty()) {
    int w = qe.top().first, u = qe.top().second;
    qe.pop();
    if (dist_optimal[u] < w)
      continue;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first, ww = adj[u][i].second;
      if (except_edge.count(ii(u, v)) > 0)
        continue;
      if (dist_optimal[u] + ww < dist_optimal[v]) {
        dist_optimal[v] = dist_optimal[u] + ww;
        qe.push(ii(-dist_optimal[v], v));
      }
    }
  }
  return dist_optimal[b] == INF ? -1 : dist_optimal[b];
}

int solve() {
  int optimal = dijkstra_optimal();
  if (optimal == -1)
    return -1;
  dfs_remove_edge(b, optimal);
  return dijsktra_suboptimal();
}

int main() {
  while (scanf("%d %d", &n, &m) && n+m) {
    init();
    scanf("%d %d", &a, &b);
    for (int i = 0; i < m; i++) {
      int x, y, w; scanf("%d %d %d", &x, &y, &w);
      adj[x].push_back(ii(y, w));
      adj_b[y].push_back(ii(x, w));
    }
    int ans = solve();
    printf("%d\n", ans);
  }
}
