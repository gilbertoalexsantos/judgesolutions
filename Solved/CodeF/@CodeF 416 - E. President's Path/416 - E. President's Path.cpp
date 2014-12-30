//Author:	Gilberto A. dos Santos
//Website:	http://codeforces.com/problemset/problem/416/E

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
const int MAX = 500;
const int INF = 1e9;

int dist[MAX][MAX];
int road[MAX][MAX];
int path[MAX][MAX];

int qt_vert, qt_edge;

void clear() {
	for(int i = 0; i < qt_vert; i++) {
		for(int j = 0; j < qt_vert; j++) {
			dist[i][j] = road[i][j] = (i == j) ? 0 : INF;
			path[i][j] = 0;
		}
	}
}

void floyd() {
	for(int k = 0; k < qt_vert; k++)
		for(int i = 0; i < qt_vert; i++) for(int j = 0; j < qt_vert; j++)
			dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

void computePaths() {
	int qt_sink[qt_vert];
	for(int source = 0; source < qt_vert; source++) {
		memset(qt_sink,0,sizeof qt_sink);

		// Veryfing if I can reach some sink with a sink adjacent vertex (that's why used road)
		for(int sink = 0; sink < qt_vert; sink++) if(dist[source][sink] != INF) for(int k = 0; k < qt_vert; k++) {
			if(k == sink) continue;
			if(dist[source][sink] == dist[source][k] + road[k][sink])
				qt_sink[sink]++;
		}
		
		// Trying all All Vertices to All possibles Sinks
		for(int sink = source+1; sink < qt_vert; sink++) if(dist[source][sink] != INF) for(int k = 0; k < qt_vert; k++) {
			if(dist[source][sink] == dist[source][k] + dist[k][sink])
				path[source][sink] += qt_sink[k];
		}
	}
}

int main() {
	scanf("%d %d",&qt_vert,&qt_edge);
	clear();
	for(int i = 0; i < qt_edge; i++) {
		int x, y, w;
		scanf("%d %d %d",&x,&y,&w);
		x--, y--;
		dist[x][y] = dist[y][x] = road[x][y] = road[y][x] = w;
	}
	floyd();
	computePaths();
	for(int i = 0; i < qt_vert; i++) for(int j = i+1; j < qt_vert; j++)
		printf("%d ",path[i][j]);
	printf("\n");
}
