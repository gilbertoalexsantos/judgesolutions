//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1746

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int MAX_VERT = 505;
const int INF = 1e9;

int n, m;
int dist[MAX_VERT][MAX_VERT];
vector<int> graph[MAX_VERT];

void clear() {
  for(int i = 0; i < n; i++) {
    graph[i].clear();
    for(int j = 0; j < n; j++)
      dist[i][j] = (i == j) ? 0 : INF;
  }
}

void floyd() {
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
}

int solve()
{
  int ans = INF;
  for(int i = 0; i < n; i++) {
  }
  return ans;
}

int main() {
  int cases = 1, T; scanf("%d",&T);
  while(T--) {
    scanf("%d %d",&n,&m);
    clear();
    for(int i = 0; i < m; i++) {
      int x, y; scanf("%d %d",&x,&y);
      graph[x].push_back(y); graph[y].push_back(x);
      dist[x][y] = dist[y][x] = 1;
    }
    floyd();
    int ans = solve();
    printf("Case #%d:\n%d\n",cases++,ans);
    puts("");
  }
}
