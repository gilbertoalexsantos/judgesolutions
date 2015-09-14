//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4829

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 1e4+5;
const int INF = 1e9;

vector<ii> adj[MAX];
int n, m;

void init() {
  for (int i = 0; i <= n; i++)
    adj[i].clear();
}

int dijkstra() {
  int dist[MAX][2];
  for (int i = 0; i < MAX; i++)
    dist[i][0] = dist[i][1] = INF;
  dist[1][0] = 0;
  priority_queue<iii> pq;
  pq.push(iii(0, ii(1, 0)));
  while (!pq.empty()) {
    int uw = -pq.top().first;
    int u = pq.top().second.first, od = pq.top().second.second;
    int du = dist[u][od];
    pq.pop();
    if (uw > du)
      continue;
    if (u == n && od == 0)
      return du;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first, w = adj[u][i].second, vod = (od+1)%2;
      if (dist[v][vod] > du+w) {
        dist[v][vod] = du+w;
        pq.push(iii(-dist[v][vod], ii(v, vod)));
      }
    }
  }
  return -1;
}

int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    init();
    for (int i = 0; i < m; i++) {
      int u, v, w; scanf("%d %d %d", &u, &v, &w);
      adj[u].push_back(ii(v, w));
      adj[v].push_back(ii(u, w));
    }

    int ans = dijkstra();
    printf("%d\n", ans);
  }
}
