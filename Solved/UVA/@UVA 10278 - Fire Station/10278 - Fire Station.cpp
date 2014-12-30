//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1219

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 500;
const int INF = 1e9;

int qt_fire, qt_vert;
bool station[MAX];
int dist[MAX][MAX];

void clear() {
	for(int i = 0; i < qt_vert; i++) for(int j = 0; j < qt_vert; j++)
		dist[i][j] = dist[j][i] = (i == j) ? 0 : INF;
	memset(station,false,sizeof station);
}

void floyd() {
	for(int k = 0; k < qt_vert; k++)
		for(int i = 0; i < qt_vert; i++) for(int j = 0; j < qt_vert; j++)
			dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

int floyd2() {
	int ans = 0, flag_max = INF;
	for(int k = 0; k < qt_vert; k++) {
		if(station[k]) continue;
		station[k] = true;
		int longest_station = -1;
		for(int i = 0; i < qt_vert; i++) {
			if(station[i]) continue;
			int nearest_station = INF;
			for(int j = 0; j < qt_vert; j++) {
				if(!station[j]) continue;
				nearest_station = min(nearest_station,dist[i][j]);
			}
			longest_station = max(longest_station,nearest_station);
		}
		station[k] = false;
		if(flag_max > longest_station) {
			flag_max = longest_station;
			ans = k+1;
		}
	} 
	return ans;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&qt_fire,&qt_vert);
		clear();
		for(int i = 0; i < qt_fire; i++) {
			int x; scanf("%d",&x);
			station[x-1] = true;
		}
		getchar();
		char w[15];
		while(fgets(w,15,stdin) && w[0] != '\n') {
			int x, y, c;
			char *f = strtok(w," ");
			x = atoi(f);
			f = strtok(NULL," ");
			y = atoi(f);
			f = strtok(NULL,"\n ");
			c = atoi(f);
			dist[x-1][y-1] = dist[y-1][x-1] = c;
		}
		floyd();
		int ans = floyd2();
		printf("%d\n",ans == 0 ? 1 : ans);
		if(T) printf("\n");
	}
}
