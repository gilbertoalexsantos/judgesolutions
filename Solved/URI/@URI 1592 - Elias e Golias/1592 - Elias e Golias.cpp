//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1592

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1005;
const int INF = 1e9;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int n, m, k;
int source, sink;
vector<int> graph[MAX];
int weight[MAX][MAX];
int memo[MAX][MAX];

void clear() {
  for(int i = 0; i < n; i++) {
    graph[i].clear();
    for(int j = 0; j < n; j++)
      weight[i][j] = INF;
  }
}

int dp(int u=0, int tk=k-1) {
  if(u == n-1)
    return 0;

  if(tk == 0)
    return INF;

  int &ret = memo[u][tk];
  if(ret != -1)
    return ret;

  ret = INF;
  for(int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i], w = weight[u][v];
    ret = min(ret,w+dp(v,tk-1));
  }

  return ret;
}

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    scanf("%d %d %d",&n,&m,&k);
    clear();
    source = 0, sink = n-1;
    for(int i = 0; i < m; i++) {
      int x, y, w; scanf("%d %d %d",&x,&y,&w);
      if(x == y || x == sink)
        continue;
      if(weight[x][y] == INF)
        graph[x].push_back(y);
      weight[x][y] = min(weight[x][y],w);
    }
    memset(memo,-1,sizeof memo);
    int ans = dp();
    printf("%d\n",ans >= INF ? -1 : ans);
  }
}
