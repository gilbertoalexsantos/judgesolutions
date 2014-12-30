//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=762

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 100;
const int INF = 1e9;

int qt_vert, qt_edge;
int dist[MAX][MAX];
int has_vert[MAX];

int ins(int x) {
	if(has_vert[x] != -1)
		return has_vert[x];
	else
		return has_vert[x] = qt_vert++;
}

void clear() {
	qt_vert = 0;
	for(int i = 0; i < MAX; i++) {
		has_vert[i] = -1;
		for(int j = 0; j < MAX; j++) {
			dist[i][j] = (i == j) ? 0 : INF;
		}
	}
}

void floyd() {
	for(int k = 0; k < qt_vert; k++)
		for(int i = 0; i < qt_vert; i++) for(int j = 0; j < qt_vert; j++)
			dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

double solve() {
	int sum = 0, qt_path = 0;
	for(int i = 0; i < qt_vert; i++) for(int j = 0; j < qt_vert; j++) {
		if(i == j) continue;
		sum += dist[i][j];	
		qt_path++;
	}
	return (double) sum/qt_path;
}

int main() {
	int cases = 1, x, y;
	while(scanf("%d %d",&x,&y) && x+y) {
		clear();
		x--, y--;
		int a = ins(x), b = ins(y);
		dist[a][b] = 1;
		while(scanf("%d %d",&x,&y) && x+y) {
			x--, y--;
			a = ins(x), b = ins(y);
			dist[a][b] = 1;
		}
		floyd();
		double ans = solve();
		printf("Case %d: average length between pages = %.3f clicks\n",cases++,ans);
	}
}
