//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1669

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

typedef pair<int, int> ii;

const int MAX_VERT = 50000 * 2 + 10;

vector<int> adj[MAX_VERT];
int size[MAX_VERT];
int degree_in[MAX_VERT];
int n1, n2, d;

int totalVerts;
int source, sink;

inline int type(int u) { return u <= n1 ? 0 : 1; }

void init() {
  totalVerts = n1 + n2, source = 0;

  for (int i = 0; i < MAX_VERT; i++) {
    adj[i].clear();
    size[i] = -1;
    degree_in[i] = 0;
  }
}

void buildGraph() {
  for (int i = 1; i <= totalVerts; i++) {
    if (degree_in[i] == 0)
     adj[source].push_back(i);
  }
}

int dfs(int u, int parent=-1) {
  if (size[u] != -1)
    return size[u];

  // SOURCE - Has a difference case
  if (u == 0) {
    int maxSize = -1;
    vector<ii> heads;
    for (int i = 0; i < adj[u].size(); i++) {
      int branchSize = dfs(adj[u][i], u);
      maxSize = max(maxSize, branchSize);
      heads.push_back(ii(type(adj[u][i]), branchSize));
    }

    int qt[2] = {0, 0};
    for (int i = 0; i < heads.size(); i++) {
      if (heads[i].second == maxSize)
        qt[heads[i].first]++;
    }

    if (qt[0] == 0 || qt[1] == 0)
      return maxSize;

    return maxSize + 1;
  }


  // NORMAL VERTICES
  int maxSize = 0;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != parent) {
      int offset = type(u) != type(v);
      maxSize = max(maxSize, offset + dfs(v, u));
    }
  }

  return size[u] = maxSize;
}

int main() {
  while (scanf("%d %d %d", &n1, &n2, &d) && n1+n2+d) {
    init();

    for (int i = 0; i < d; i++) {
      int u, v; scanf("%d %d", &u, &v);
      adj[v].push_back(u);
      degree_in[u]++;
    }

    buildGraph();

    printf("%d\n", dfs(0) + 2);
  }
}
