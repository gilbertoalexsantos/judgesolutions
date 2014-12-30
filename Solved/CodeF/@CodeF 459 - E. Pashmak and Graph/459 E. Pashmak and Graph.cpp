#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 300005;

struct EDGE {
  int u, v, w;
  EDGE(int u, int v, int w) : u(u), v(v), w(w) {}
  bool operator<(const EDGE &v) const { return w < v.w; }
};

int qt_vert, qt_edges;
vector<EDGE> edges;
int f[MAX], dp[MAX];

int main() {
  scanf("%d %d",&qt_vert,&qt_edges);
  memset(f,0,sizeof f);
  memset(dp,0,sizeof dp);
  for(int i = 0; i < qt_edges; i++) {
    int x, y, w; scanf("%d %d %d",&x,&y,&w);
    edges.push_back(EDGE(x,y,w));
  }
  sort(edges.begin(),edges.end());
  int i = 0;
  while(i < qt_edges) {
    int left = i, right = i;
    while(right < qt_edges && edges[right].w == edges[left].w)
      right++;
    for(int l = left; l < right; l++)
      f[edges[l].v] = max(f[edges[l].v],dp[edges[l].u]+1);
    for(int l = left; l < right; l++)
      dp[edges[l].v] = max(f[edges[l].v],dp[edges[l].v]);
    i = right;
  }
  int ans = 0;
  for(int i = 1; i <= qt_vert; i++)
    ans = max(ans,dp[i]);
  printf("%d\n",ans);
}
