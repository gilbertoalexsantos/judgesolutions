//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1043

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int manhattan_distance(int x0, int y0, int x1, int y1) { return abs(x0 - x1) + abs(y0 - y1); }

int main() {
	int size;
	while(scanf("%d",&size) != EOF) {

		char m[size][size];

		for(int i = 0; i < size; i++) scanf("%s",m[i]);

		int ans = -1;
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				if(m[i][j] == '1') {
					int best = 100000000;
					for(int l = 0; l < size; l++) {
						for(int c = 0; c < size; c++) {
							if(m[l][c] == '3') {
								best = min(best,manhattan_distance(i,j,l,c));
							}
						}
					}
					ans = max(ans,best);
				}
			}
		}

		printf("%d\n",ans);
	}
}

