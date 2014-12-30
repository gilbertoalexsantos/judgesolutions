//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3589

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_VERT = 100005;
const int INF = 1e9;

int dist[MAX_VERT];
vector<int> graph[MAX_VERT];
int qt_vert;

void clear() {
  for(int i = 0; i < qt_vert; i++)
    graph[i].clear();
}

int bfs(int source, int sink) {
  int dist[qt_vert];
  memset(dist,-1,sizeof dist);
  queue<int> qe;
  qe.push(source);
  dist[source] = 0;
  while(!qe.empty()) {
    int u = qe.front(); qe.pop();
    if(u == sink)
      return dist[u];
    for(int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if(dist[v] == -1)
        dist[v] = dist[u]+1, qe.push(v);
    }
  }
  return INF;
}

int main() {
  int qt; scanf("%d",&qt);
  while(qt--) {
    clear();
    scanf("%d",&qt_vert);
    for(int i = 0; i < qt_vert; i++) {
      int u, k; scanf("%d %d",&u,&k);
      while(k--) {
        int v; scanf("%d",&v);
        graph[u].push_back(v);
      }
    }
    int a, b; scanf("%d %d",&a,&b);
    int ans = bfs(a,b);
    printf("%d %d %d\n",a,b,ans-1);
    if(qt) puts("");
  }
}
