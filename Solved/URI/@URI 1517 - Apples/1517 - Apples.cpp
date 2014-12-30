//Author:	Gilberto A. dos Santos
//Website:	http://www.urionlinejudge.com.br/judge/pt/problems/view/1517

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct point {
	int x, y, t;

	point() { x = y = t = 0; }
};

int d_dist[1010];
vector<int> graph[1010];

int bfs(int x, int y) {
	d_dist[x] = 0;
	for(int i = 0; i <= y; i++) {
		if(d_dist[i] == 1e9) continue;
		for(int j = 0; j < graph[i].size(); j++) {
			int v = graph[i][j], w = -1;
			if(d_dist[v] > d_dist[i] + w) d_dist[v] = d_dist[i] + w;
		}
	}
	return d_dist[y];
}

int dist(point a, point b) { 
	int dl = abs(a.x - b.x);
	int dc = abs(a.y - b.y);
	int md = dl + dc;
	if(a.x == b.x || a.y == b.y) return md;
	return dl + dc - (min(dl,dc));
}

bool check(point a, point b) { return dist(a,b) <= abs(a.t-b.t); }

void create_graph(point init, int qt_apple, const vector<point> &arr) {
	int source = 0, sink = qt_apple+1;
	for(int i = 0; i < qt_apple; i++) {
		for(int j = i+1; j < qt_apple; j++) {
			if(!check(arr[i],arr[j])) continue;
			graph[i+1].push_back(j+1);
		}
		graph[i+1].push_back(sink);
	}
	for(int i = 0; i < qt_apple; i++) {
		if(!check(init,arr[i])) continue;
		graph[source].push_back(i+1);
	}
}

void clear(int n) {
	for(int i = 0; i <= n; i++) {
		graph[i].clear();
		d_dist[i] = 1e9;
	}
}

int main() {
	int row, col, qt_apple;
	while(scanf("%d %d %d",&row,&col,&qt_apple) && row+col+qt_apple) {
		clear(qt_apple+3);
		vector<point> arr;
		for(int i = 0; i < qt_apple; i++) {
			point t;
			scanf("%d %d %d",&t.x,&t.y,&t.t);
			arr.push_back(t);
		}
		point init;
		scanf("%d %d",&init.x,&init.y);
		create_graph(init,qt_apple,arr);
		printf("%d\n",-bfs(0,qt_apple+1)-1);
	}
}
