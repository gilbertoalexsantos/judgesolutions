//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int MAX_VERT = 100;
const int INF = 1e9;

int qt_vert;
vector<ii> graph[MAX_VERT];
int dist[MAX_VERT];

void clear() {
  for(int i = 0; i < qt_vert; i++) {
    graph[i].clear();
    dist[i] = INF;
  }
}

bool bfs(int source, int sink) {
  queue<int> qe;
  qe.push(source);
  bool visited[qt_vert];
  memset(visited,0,sizeof visited);
  visited[source] = true;
  while(!qe.empty()) {
    int v = qe.front(); qe.pop();
    for(int i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i].first;
      if(!visited[nv]) {
        visited[nv] = true;
        if(nv == sink) return true;
        qe.push(nv);
      }
    }
  }
  return false;
}

bool bellman() {
  dist[0] = -100;

  for(int i = 0; i < qt_vert-1; i++)
    for(int j = 0; j < qt_vert; j++) for(int z = 0; z < graph[j].size(); z++) {
        int v = j, nv = graph[j][z].first, nw = graph[j][z].second;
        if(dist[v]+nw >= 0) continue;
        dist[nv] = min(dist[nv],dist[v]+nw);
      }

  if(dist[qt_vert-1] < 0) return true;

  for(int i = 0; i < qt_vert; i++) for(int j = 0; j < graph[i].size(); j++) {
      int v = i, nv = graph[i][j].first, nw = graph[i][j].second;

      if(dist[v]+nw >= 0) continue;

      if(dist[nv] > dist[v]+nw) {
        if(bfs(v,qt_vert-1)) return true;
      }
    }

  return dist[qt_vert-1] < 0;
}

int main() {
  while(scanf("%d",&qt_vert) && qt_vert > 0) {
    clear();
    for(int i = 0; i < qt_vert; i++) {
      int w, qt_ed; scanf("%d %d",&w,&qt_ed);
      for(int j = 0; j < qt_ed; j++) {
        int x; scanf("%d",&x);
        x--;
        graph[i].push_back(ii(x,-w));
      }
    }
    bool ans = bellman();
    printf("%s\n",ans ? "winnable" : "hopeless");
  }
}
