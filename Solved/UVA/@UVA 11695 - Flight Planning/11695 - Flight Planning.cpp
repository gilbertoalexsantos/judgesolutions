//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2742

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int MAX_VERT = 2500;
const int INF = 1e9;

int qt_vert;
vector<int> graph[MAX_VERT];
vector<int> flag_path;
vector<ii> edge;
int dist[MAX_VERT], path[MAX_VERT];
ii edge_off;

void clear() {
	edge_off = ii(-1,-1);
	edge.clear();
	for(int i = 0; i < qt_vert; i++) {
		graph[i].clear();
	}
}

inline bool check(int x, int y) { return (x == edge_off.first && y == edge_off.second) || (x == edge_off.second && y == edge_off.first); }

ii bfs(int x, bool len = false) {
	memset(dist,-1,sizeof dist);
	memset(path,-1,sizeof path);
	queue<int> qe; qe.push(x);
	dist[x] = 0;
	while(!qe.empty()) {
		int v = qe.front(); qe.pop();
		for(int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if(check(v,nv) || dist[nv] != -1) continue;
			dist[nv] = dist[v] + 1, path[nv] = v, qe.push(nv);
		}
	}
	int flag_max = -1, ret;
	for(int i = 0; i < qt_vert; i++) {
		if(flag_max < dist[i])
			flag_max = dist[i], ret = i;
	}
	return ii(ret,flag_max);
}

ii getCenter(int v) {
	flag_path.clear();
	int x = bfs(v).first;
	int y = bfs(x).first;
	flag_path.push_back(y);
	while(path[y] != -1) {
		flag_path.push_back(path[y]);
		y = path[y];
	}
	reverse(flag_path.begin(),flag_path.end());
	int center = flag_path[flag_path.size() / 2];
	return make_pair(center,flag_path.size());
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%d",&qt_vert);
		clear();
		for(int i = 0; i < qt_vert-1; i++) {
			int x, y; scanf("%d %d",&x,&y); x--, y--;	
			edge.push_back(ii(x,y));
			graph[x].push_back(y), graph[y].push_back(x);
		}
		int max_len = INF;
		ii worst_edge, add_edge;
		for(int i = 0; i < edge.size(); i++) {
			edge_off = edge[i];
			ii c1 = getCenter(edge[i].first);
			ii c2 = getCenter(edge[i].second);
			int max1 = max(c1.second-1,c2.second-1);
			int new_diameter = max(max1,c1.second/2 + c2.second/2 + 1);
			if(new_diameter < max_len) {
				max_len = new_diameter;
				worst_edge = edge_off;
				add_edge = ii(c1.first,c2.first);
			}
		}
		printf("%d\n",max_len);
		printf("%d %d\n",worst_edge.first+1,worst_edge.second+1);
		printf("%d %d\n",add_edge.first+1,add_edge.second+1);
	}
}
