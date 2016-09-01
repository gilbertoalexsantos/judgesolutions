//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1838

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

const int MAX_STONES = 1e3 + 5;
const int INF = 1e9;

ii stones[MAX_STONES];
int n;
int source, sink;
vector<ii> adj[MAX_STONES];
int dp[MAX_STONES];

void buildGraph() {
  source = 0, sink = n+1;

  // Pushing source and sink
  for (int i = 0; i < n; i++) {
    adj[source].push_back(ii(i+1, stones[i].first - 1));
    adj[i+1].push_back(ii(sink, 3600 - stones[i].second));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (stones[i].second <= stones[j].first) {
        adj[i+1].push_back(ii(j+1, stones[j].first - stones[i].second));
      }
    }
  }
}

void prepareDp() {
  memset(dp, -1, sizeof dp);
  dp[sink] = 1;
}

int dfs(int u, int p=-1) {
  if (dp[u] != -1)
    return dp[u];

  dp[u] = INF;

  for (int i = 0; i < (int)adj[u].size(); i++) {
    if (adj[u][i].first == p)
      continue;
    dp[u] = min(dp[u], adj[u][i].second + dfs(adj[u][i].first, u));
  }

  return dp[u];
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d %d", &stones[i].first, &stones[i].second);

  buildGraph();
  prepareDp();
  int ans = 3600 - dfs(source);

  printf("%d\n", ans);
}
