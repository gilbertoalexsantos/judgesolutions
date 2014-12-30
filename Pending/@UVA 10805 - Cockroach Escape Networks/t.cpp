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
typedef vector<vector<int> > vvi;

const int MAX_VERT = 505;
const int INF = 1e9;

int n, m;
vvi graph(MAX_VERT);

void inline pb(int x, int y, vvi &v) {
  v[x].push_back(y), v[y].push_back(x);
}

void clear() {
	for(int i = 0; i < n; i++) {
    graph[i].clear();
  }
}

vvi getSpanningTree(int x) {
  bool visited[n]; memset(visited,false,sizeof visited);
  visited[x] = true;
  queue<int> qe; qe.push(x);
  vvi ret(n);
  while(!qe.empty()) {
    int v = qe.front(); qe.pop();
    for(int i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i];
      if(!visited[nv])
        visited[nv] = true, pb(v,nv,ret), qe.push(nv);
    }
  }
  return ret;
}

int bfs(int x, vvi g, int y = -1) {
  int dist[n]; memset(dist,-1,sizeof dist);
  dist[x] = 0;
  queue<int> qe; qe.push(x);
  int max_dist = -1, ret;
  while(!qe.empty()) {
    int v = qe.front(); qe.pop();
    if(v == y)
      break;
    for(int i = 0; i < g[v].size(); i++) {
      int nv = g[v][i];
      if(dist[nv] == -1) {
        dist[nv] = dist[v] + 1, qe.push(nv);
        if(max_dist < dist[nv])
          max_dist = dist[nv], ret = nv;
      }
    }
  }

  if(y != -1)
    return dist[y];

  return ret;
}

void pr(vvi v) {
  for(int i = 0; i < n; i++) {
    printf("[%d]",i);
    for(int j = 0; j < v[i].size(); j++)
      printf(" => [%d]",v[i][j]);
    printf("\n");
  }
}

int getDiameter(vvi tree) {
  int x = bfs(0,tree);
  int y = bfs(x,tree);
  return bfs(x,tree,y);
}

int solve() {
  int ans = INF;
  for(int i = 0; i < n; i++) {
    vvi spanning_tree = getSpanningTree(i);
    int diameter = getDiameter(spanning_tree);
    ans = min(ans,diameter);
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
      pb(x,y,graph);
		}
		int ans = solve();
		printf("Case #%d:\n%d\n",cases++,ans);
		puts("");
	}
}

