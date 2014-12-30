//Author:  Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1747

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 101;
const int INF = 1e9;

int qt_verts, qt_edges;
int source, sink;
vector<int> graph[MAX];
int edge[MAX][MAX];

void clear() {
  for(int i = 1; i <= qt_verts; i++) {
    graph[i].clear();
    for(int j = 1; j <= qt_verts; j++) {
      edge[i][j] = INF;
    }
  }
}

int dijkstra() {
  priority_queue<ii> pq;
  pq.push(ii(0,source));
  int dist[qt_verts+1], path[qt_verts+1];
  for(int i = 1; i <= qt_verts; i++) {
    dist[i] = INF;
    path[i] = -1;
  }
  dist[source] = 0;
  while(!pq.empty()) {
    int u = pq.top().second, w = -pq.top().first; pq.pop();
    if(dist[u] < w)
      continue;
    if(u == sink)
      break;
    for(int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i], nw = edge[u][v];
      if(dist[v] > dist[u]+nw) {
        path[v] = u;
        dist[v] = dist[u]+nw;
        pq.push(ii(-dist[v],v));
      }
    }
  }
  stack<int> p;
  int t = sink;
  while(t != -1) {
    p.push(t);
    t = path[t];
  }
  int u = source;
  while(!p.empty()) {
    int v = p.top(); p.pop();
    edge[u][v] = INF;
    edge[v][u] *= -1;
    u = v;
  }
  return dist[sink];
}

int bellman() {
  int dist[qt_verts+1];
  for(int i = 1; i <= qt_verts; i++) {
    dist[i] = INF;
  }
  dist[source] = 0;
  for(int i = 0; i < qt_verts-1; i++) {
    for(int u = 1; u <= qt_verts; u++) {
      for(int j = 0; j < graph[u].size(); j++) {
        int v = graph[u][j], w = edge[u][v];
        dist[v] = min(dist[v],dist[u]+w);
      }
    }
  }
  return dist[sink];
}

int solve() {
  int d1 = dijkstra();
  int d2 = bellman();
  if(d1 == INF || d2 == INF)
    return -1;
  return d1 + d2;
}

int main() {
  while(scanf("%d",&qt_verts) && qt_verts) {
    clear();
    source = 1, sink = qt_verts;
    scanf("%d",&qt_edges);
    for(int i = 0; i < qt_edges; i++) {
      int u, v, w; scanf("%d %d %d",&u,&v,&w);
      graph[u].push_back(v); graph[v].push_back(u);
      edge[u][v] = edge[v][u] = w;
    }
    int ans = solve();
    if(ans == -1) printf("Back to jail\n");
    else printf("%d\n",ans);
  }
}
