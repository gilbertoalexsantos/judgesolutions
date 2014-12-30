//Author: Gilberto A. dos Santos
//Website:  http://br.spoj.com/problems/CHUVA08/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> iii;

const int INF = 1e9;

ii source, sink;
int so, si, qt_vert;
vector<iii> cover;
vector<ii> graph[1000005];

inline int mdistance(ii a, ii b) { return abs(b.first - a.first) + abs(b.second - a.second); }

inline void ins(int a, int b, int w) {
  graph[a].push_back(ii(b,w));
  graph[b].push_back(ii(a,w));
}

int calc(int u, int v) {
  int dx = max(0, max(cover[u].first.first,cover[v].first.first)-
      min(cover[u].second.first,cover[v].second.first));
  int dy = max(0, max(cover[u].first.second,cover[v].first.second)-
      min(cover[u].second.second,cover[v].second.second));
  return dx + dy;
}

int dijkstra() {
  int dist[qt_vert];
  for(int i = 0; i < qt_vert; i++)
    dist[i] = INF;
  priority_queue<ii> pq;
  pq.push(ii(0,so));
  dist[so] = 0;
  while(!pq.empty()) {
    int u = pq.top().second, w = -pq.top().first; pq.pop();
    if(dist[u] < w)
      continue;
    for(int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i].first, wv = graph[u][i].second;
      if(dist[v] > dist[u]+wv)
        dist[v] = dist[u]+wv, pq.push(ii(-dist[v],v));
    }
  }
  return dist[si];
}

int main() {
  scanf("%d %d %d %d",&source.first,&source.second,&sink.first,&sink.second);
  int k; scanf("%d",&k);
  cover.push_back(iii(source,source));
  for(int i = 0; i < k; i++) {
    ii t1, t2;
    scanf("%d %d %d %d",&t1.first,&t1.second,&t2.first,&t2.second);
    cover.push_back(iii(t1,t2));
  }
  cover.push_back(iii(sink,sink));

  so = 0, si = cover.size()-1; qt_vert = cover.size();
  for(int i = 0; i < qt_vert; i++)
    graph[i].clear();
  graph[so].push_back(ii(si,calc(so,si)));
  for(int i = 1; i+1 < cover.size(); i++) {
    graph[so].push_back(ii(i,calc(so,i)));
    graph[i].push_back(ii(si,calc(i,si)));
    for(int j = i+1; j+1 < cover.size(); j++)
      ins(i,j,calc(i,j));
  }
  int ret = dijkstra();
  printf("%d\n",ret);
}
