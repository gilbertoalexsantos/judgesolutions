//Author: Gilberto A. dos Santos
//Website: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=866&page=show_problem&problem=4898

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<long double, int> di;

const int QT_VERT = 1005;
const long double MAX_T = 1440.0;
const long double INF = 1e10;
const long double EPS = 1e-9;

inline bool greaterThan(long double a, long double b) { return (a - b) > EPS; }

struct EDGE {
  int v;
  long double a, b;
  EDGE(int v, long double a, long double b) : v(v), a(a), b(b) {}
  long double cost(long double t) { return a * t + b; }
};

int n, m;
vector<EDGE> adj[QT_VERT];

void init() {
  for (int i = 0; i <= n; i++)
    adj[i].clear();
}

long double dijkstra(long double t) {
  int lo = 1, hi = n;

  long double dist[n+1];
  for (int i = 0; i <= n; i++)
    dist[i] = INF;
  dist[lo] = 0.0;

  priority_queue<di> pq;
  pq.push(di(0.0, lo));
  
  while (!pq.empty()) {
    int u = pq.top().second;
    long double w = -pq.top().first;
    pq.pop();
    if (w < dist[u])
      continue;
    if (u == hi)
      return dist[u];
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].v;
      long double w = adj[u][i].cost(t);
      if (greaterThan(dist[v], dist[u]+w)) {
        dist[v] = dist[u]+w;
        pq.push(di(-dist[v], v));
      }
    }
  }

  return dist[hi];
}

long double ternary_search() {
  long double lo = 0, hi = MAX_T;
  for (int i = 0; i < 500; i++) {
    long double le = lo + (hi - lo) / 3.0;
    long double ri = hi - (hi - lo) / 3.0;
    if (dijkstra(le) < dijkstra(ri))
      lo = le;
    else
      hi = ri;
  }
  return dijkstra(hi);
}

int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    init();
    
    for (int i = 0; i < m; i++) {
      int u, v;
      long double a, b;
      scanf("%d %d %Lf %Lf", &u, &v, &a, &b);
      adj[u].push_back(EDGE(v, a, b));
      adj[v].push_back(EDGE(u, a, b));
    }

    long double ans = ternary_search();
    printf("%.5Lf\n", ans);
  }
}
