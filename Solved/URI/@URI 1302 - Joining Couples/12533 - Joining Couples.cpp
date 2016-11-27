//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3978

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_VERT = 1e5 + 5;
const int MAX_VERT_LOG = 17;

int n;
int adj[MAX_VERT];
vector<int> adjBack[MAX_VERT];
int comp[MAX_VERT];
bool inCycle[MAX_VERT];
int posCycle[MAX_VERT];
int cycleSize[MAX_VERT];
int firstCycle[MAX_VERT];
int memo[MAX_VERT][MAX_VERT_LOG];
int level[MAX_VERT];

void init() {
  memset(memo, -1, sizeof memo);
  for (int i = 0; i < n; i++) {
    adjBack[i].clear();
    comp[i] = i;
    inCycle[i] = false;
    posCycle[i] = -1;
    cycleSize[i] = 0;
    firstCycle[i] = i;
    level[i] = 0;
  }
}

void dfs(int u, int p) {
  for (int i = 0; i < (int)adjBack[u].size(); i++) {
    int v = adjBack[u][i];
    if (posCycle[v] == -1) {
      memo[v][0] = p;
      level[v] = level[u] + 1;
      posCycle[v] = posCycle[u];
      comp[v] = comp[u];
      dfs(v, v);
    }
  }
}

void calcCycles() {
  bool visited[n]; memset(visited, false, sizeof visited);
  int cntComp = 0;
  for (int i = 0; i < n; i++) {
    if (posCycle[i] != -1)
      continue;

    int cycle = i;
    while (!visited[cycle]) {
      visited[cycle] = true;
      cycle = adj[cycle];
    }

    int v = cycle, cnt = 0;
    do {
      posCycle[v] = cnt++;
      comp[v] = cntComp;
      inCycle[v] = true;
      v = adj[v];
    } while (v != cycle);

    memo[cycle][0] = cycle;
    cycleSize[cntComp] = cnt;
    firstCycle[cntComp++] = cycle;
    level[cycle] = 0;

    do {
      dfs(v, cycle);
      v = adj[v];
    } while (v != cycle);
  }

  for (int j = 1; 1 << j < n; j++)
    for (int i = 0; i < n; i++)
      if (memo[i][j-1] != -1)
        memo[i][j] = memo[memo[i][j-1]][j-1];
}

int solve(int u, int v) {
  if (comp[u] != comp[v])
    return -1;

  int diffInCycle = abs(posCycle[u] - posCycle[v]);
  diffInCycle = min(diffInCycle, cycleSize[comp[u]] - diffInCycle);

  if (inCycle[u])
    u = firstCycle[comp[u]];
  if (inCycle[v])
    v = firstCycle[comp[v]];

  if (level[u] < level[v])
    swap(u, v);

  int u0 = u, v0 = v;

  int log;
  for (log = 1; 1 << log <= level[u]; log++);
  log--;
  for (int i = log; i >= 0; i--)
    if (level[u] - (1 << i) >= level[v])
      u = memo[u][i];

  if (u == v) {
    return level[u0] - level[u] + diffInCycle;
  } else {
    for (int i = log; i >= 0; i--)
      if (memo[u][i] != -1 && memo[u][i] != memo[v][i])
        u = memo[u][i], v = memo[v][i];
    return level[u0] - level[u] + level[v0] - level[v] + diffInCycle + 2;
  }
}

int main() {
  while (scanf("%d", &n) != EOF) {
    init();

    for (int u = 0; u < n; u++) {
      scanf("%d", &adj[u]);
      adj[u]--;
      adjBack[adj[u]].push_back(u);
    }

    calcCycles();

    int q; scanf("%d", &q);
    while (q--) {
      int u, v; scanf("%d %d", &u, &v);
      u--, v--;
      printf("%d\n", solve(u, v));
    }
  }
}
