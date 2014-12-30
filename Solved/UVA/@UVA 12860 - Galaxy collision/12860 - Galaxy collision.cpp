//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4725

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef map<ii, int>::iterator IT;

const int INF = 1e9;
const int MAX = (5*1e4) + 10;
const int MAX_RANGE = 1e5 + 10;

int n;
map<ii, int> m;
vector<ii> points;
vector<int> graph[MAX];
bool visited[MAX];

void clear() {
  m.clear();
  points.clear();
  for(int i = 0; i < n; i++) {
    graph[i].clear();
    visited[i] = false;
  }
}

bool can(ii u, ii v) {
  int d1 = u.first-v.first, d2 = u.second-v.second;
  return d1*d1+d2*d2 <= 25;
}

void createGraph() {
  for(int i = 0; i < n; i++) {
    ii u = points[i];
    for(int x = -5; x <= +5; x++) {
      for(int y = -5; y <= +5; y++) {
        if(x == 0 && y == 0)
          continue;
        ii v = ii(u.first+x,u.second+y);
        IT it = m.find(v);
        if(it != m.end() && can(u,v))
          graph[i].push_back(it->second);
      }
    }
  }
}

void pr() {
  for(int i = 0; i < n; i++) {
    printf("[(%d,%d]]",points[i].first,points[i].second);
    for(int j = 0; j < graph[i].size(); j++) {
      int p = graph[i][j];
      printf(" => [%d,%d]",points[p].first,points[p].second);
    }
    puts("");
  }
  puts("");  
}

int bfs(int u) {
  queue<ii> qe;
  qe.push(ii(u,0));
  visited[u] = true;
  int st[2];
  st[0] = st[1] = 0;
  while(!qe.empty()) {
    int u = qe.front().first;
    int s = qe.front().second;
    qe.pop();
    st[s]++;
    for(int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if(!visited[v])
        visited[v] = true, qe.push(ii(v,!s));
    }
  }
  return min(st[0],st[1]);
}

int main() {
  while(scanf("%d",&n) != EOF) {
    clear();
    for(int i = 0; i < n; i++) {
      int x, y; scanf("%d %d",&x,&y);
      m[ii(x,y)] = i;
      points.push_back(ii(x,y));
    }
    createGraph();
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(visited[i])
        continue;
      ans += bfs(i);
    }
    printf("%d\n",ans);
  }
}
