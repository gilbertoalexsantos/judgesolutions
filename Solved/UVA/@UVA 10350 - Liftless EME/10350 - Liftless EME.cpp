//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1291

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

char word[15];
int n, m;
int dist[15][2];

void clear() {
	for(int i = 0; i < 15; i++)
		dist[i][0] = dist[i][1] = INF;
}

int main() {
	while(scanf("%s",word) != EOF) {
		clear();
		scanf("%d %d",&n,&m);
		bool flag = true;
		int debug = 0;
		for(int i = 0; i < n - 1; i++) {
			for(int j = 0; j < m; j++) {
				for(int k = 0; k < m; k++) {
					int c; scanf("%d",&c); c += 2;
					if(i == 0)
						dist[k][flag] = min(dist[k][flag],c);
					else
						dist[k][flag] = min(dist[k][flag],dist[j][!flag] + c);
				}
			}
			flag = !flag;
			for(int z = 0; z < m; z++)
				dist[z][flag] = INF;
		}
		int ans = INF;
		for(int i = 0; i < 15; i++)
			ans = min(ans,dist[i][!flag]);
		printf("%s\n%d\n",word,ans);
	}
}
