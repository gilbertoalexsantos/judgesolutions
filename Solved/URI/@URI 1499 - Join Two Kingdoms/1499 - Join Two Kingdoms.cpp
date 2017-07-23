//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1499

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VERT = 1e5;

int n[2];
vector<int> adj[MAX_VERT][2];
long dist[MAX_VERT][2];
int parent[MAX_VERT][2];
long qtHeight[MAX_VERT][2];
long diameter[2];
long height[2];
long radius[2];

void clear() {
  for (int i = 0; i < n[0]; i++)
    adj[i][0].clear();
  for (int i = 0; i < n[1]; i++)
    adj[i][1].clear();
}

pair<long, int> longestVertex(int a, int u, int p = -1, int h = 0, int otherCenter=-1) {
  dist[u][a] = h;

  long maxHeight = h; int maxVertex = u;
  qtHeight[h][a]++;
  for (int i = 0; i < (int)adj[u][a].size(); i++) {
    int v = adj[u][a][i];
    if (v == p || v == otherCenter)
      continue;
    pair<long, int> pp = longestVertex(a, v, u, h+1);
    if (pp.first > maxHeight) {
      maxHeight = pp.first;
      maxVertex = pp.second;
    }
    parent[v][a] = u;
  }

  return pair<long, int>(maxHeight, maxVertex);
}

void process(int a) {
  int u = longestVertex(a, 0).second;
  for (int i = 0; i < n[a]; i++)
    parent[i][a] = -1;

  int v = longestVertex(a, u).second;

  vector<int> path;
  do {
    path.push_back(v);
    v = parent[v][a];
  } while (v != -1);

  int size = path.size() - 1;
  int center1 = path[size / 2];
  int center2 = size % 2 != 0 ? path[size / 2 + 1] : -1;

  for (int i = 0; i < n[a]; i++)
    qtHeight[i][a] = 0;

  longestVertex(a, center1, -1, 0, center2);
  if (center2 != -1)
    longestVertex(a, center2, -1, 0, center1);

  if (center2 != -1) {
    dist[center2][a] = 0;
    qtHeight[0][a] = 2;
  }

  diameter[a] = size;

  height[a] = size / 2;
  radius[a] = size / 2 + (size % 2 != 0);
}

long double solve() {
  process(0); process(1);

  // printf("%d %d\n-----\n", height[0], height[1]);
  // printf("RadiusLeft %d | RadiusRight %d\n----\n", radius[0], radius[1]);

  long qt = 0;
  long sum = 0;
  for (long i = 0; i <= height[0]; i++) {
    for (long j = 0; j <= height[1]; j++) {
      // printf("Height left: %d | Height right: %d\n", i, j);
      // printf("QtLeft: %d | QtRight: %d\n", qtHeight[i][0], qtHeight[j][1]);
      // printf("DiameterLeft: %d | DiameterRight: %d\n", diameter[0], diameter[1]);
      // printf("******\n");
      qt += qtHeight[i][0] * qtHeight[j][1];

      long a = diameter[0];
      long b = diameter[1];
      long c = 1LL + radius[0] + radius[1] + i + j;

      long t = -1;
      if (t < a) t = a;
      if (t < b) t = b;
      if (t < c) t = c;

      sum += qtHeight[i][0] * qtHeight[j][1] * t;
    }
  }

  return (long double)sum / (long double)qt;
}

int main() {
  while (scanf("%d %d", &n[0], &n[1]) != EOF) {
    clear();

    for (int i = 0; i < n[0]-1; i++) {
      int u, v; scanf("%d %d", &u, &v);
      u--, v--;
      adj[u][0].push_back(v); adj[v][0].push_back(u);
    }

    for (int i = 0; i < n[1]-1; i++) {
      int u, v; scanf("%d %d", &u, &v);
      u--, v--;
      adj[u][1].push_back(v); adj[v][1].push_back(u);
    }

    printf("%.3Lf\n", solve());
  }
}

