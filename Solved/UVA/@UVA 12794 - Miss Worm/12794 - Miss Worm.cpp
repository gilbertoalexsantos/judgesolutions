//Author: Gilberto A. dos Santos
//Website:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4659

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int MAX = 10005;
const int INF = 1e9;

int n, m;
vector<ii> graph[MAX];
vector<ii> st;

int component[MAX], size_cycle[MAX], pos_cycle[MAX];
int dist[MAX];
int cnt_component, cnt_cycle;
bool visited[MAX];

void clear() {
  cnt_component = cnt_cycle = 0;
  st.clear();
  for(int i = 0; i <= n; i++) {
    graph[i].clear(); 
    visited[i] = false;
    component[i] = -1;
    size_cycle[i] = 0;
    pos_cycle[i] = -1;
  }
}

void get_cycle(int u, int v, int w, int cmp) {
  pos_cycle[u] = pos_cycle[v] = cmp;
  int p = st.size()-1;
  int sum_cycle = w;
  while(st[p].first != v) {
    pos_cycle[st[p].first] = cmp;
    sum_cycle += st[p--].second;
  }
  sum_cycle += st[p].second;
  size_cycle[cmp] = sum_cycle;
}

void dfs(int u, int cmp, int parent=-1) {
  visited[u] = true;
  component[u] = cmp;
  for(int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i].first, w = graph[u][i].second;
    if(visited[v]) {
      if(v != parent && pos_cycle[v] == -1)
        get_cycle(u,v,w,cnt_cycle++);
    }
    else
      st.push_back(ii(u,w)), dfs(v,cmp,u);
  }
  if(!st.empty())
    st.pop_back();
}

void init_cycle() {
  for(int i = 1; i <= n; i++) if(!visited[i])
    dfs(i,cnt_component++);
}

void dijkstra(int u) {
  for(int i = 1; i <= n; i++)
    dist[i] = INF;
  priority_queue<ii> pq;
  dist[u] = 0;
  pq.push(ii(0,u));
  while(!pq.empty()) {
    int u = pq.top().second, w = -pq.top().first; pq.pop();
    if(dist[u] < w)
      continue;
    for(int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i].first, nw = graph[u][i].second;
      if(dist[v] > dist[u]+nw) {
        dist[v] = dist[u]+nw;
        pq.push(ii(-dist[v],v));
      }
    }
  }
}

int solve(int u, int warm) {
  dijkstra(u);
  int ret = INF;
  for(int i = 1; i <= n; i++) {
    if(pos_cycle[i] != -1 && size_cycle[pos_cycle[i]] >= warm)
      ret = min(ret,2*dist[i] + size_cycle[pos_cycle[i]]);
  }
  return ret == INF ? -1 : ret;
}

int main() {
  while(scanf("%d %d",&n,&m) != EOF) {
    clear();
    for(int i = 0; i < m; i++) {
      int x, y, w; scanf("%d %d %d",&x,&y,&w);
      graph[x].push_back(ii(y,w));
      graph[y].push_back(ii(x,w));
    }
    init_cycle();
    int Q; scanf("%d",&Q);
    while(Q--) {
      int u, warm; scanf("%d %d",&u,&warm);
      int ans = solve(u,warm);
      printf("%d\n",ans);
    } 
  }
}
