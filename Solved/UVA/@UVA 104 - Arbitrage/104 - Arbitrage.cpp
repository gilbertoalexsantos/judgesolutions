//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=40

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 20;
const double EPS = 1e-9;
const int INF = 1e9;

int size;
double dist[MAX][MAX][MAX];
int path[MAX][MAX][MAX];

inline bool gT(double a, double b) { return (a - b) > EPS; }

void clear() {
	memset(dist,0,sizeof dist);
	memset(path,-1,sizeof path);
}

void floyd() {
	for(int l = 1; l < size; l++)
		for(int k = 0; k < size; k++)
			for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) {
				double t = dist[l-1][i][k] * dist[0][k][j];
				if(gT(t,dist[l][i][j])) {
					dist[l][i][j] = t;
					path[l][i][j] = k;
				}
			}
}

int main() {
	while(scanf("%d",&size) != EOF) {
		clear();

		for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) {
			path[0][i][j] = i;
			if(i == j) 
				dist[0][i][j] = 1.0;
			else 
				scanf("%lf",&dist[0][i][j]);
		}

		floyd();

		int index = -1, len;
		for(int l = 1; l < size; l++) {
			for(int i = 0; i < size; i++) {
				if(gT(dist[l][i][i],1.01)) {
					index  = i, len = l;
					break;
				}
			}
			if(index != -1) break;
		}

		if(index == -1) 
			printf("no arbitrage sequence exists\n");
		else {
			vector<int> ans;
			ans.push_back(index);
			int c = index;
			for(int l = len; l >= 0; l--) {
				c = path[l][index][c];
				ans.push_back(c);
			}
			printf("%d",ans[ans.size()-1]+1);
			for(int i = ans.size()-2; i >= 0; i--)
				printf(" %d",ans[i]+1);
			printf("\n");
		}
	}
}
