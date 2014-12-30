//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3703

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

char grid1[6][6], grid2[6][6];
char ans[6];

void T_sort() {
	for(int COL = 0; COL < 5; COL++) {
		for(int i = 6; i >= 0; i--) {
			for(int j = 1; j < i; j++) {
				if(grid1[j][COL] < grid1[j-1][COL])
					swap(grid1[j][COL],grid1[j-1][COL]);
				if(grid2[j][COL] < grid2[j-1][COL])
					swap(grid2[j][COL],grid2[j-1][COL]);
			}
		}
	}
}

bool bb(int a, int b, int c, int d, int e) {
	int r1,r2,r3,r4,r5,sum;
	r1 = r2 = r3 = r4 = r5 = sum = 0;
	for(int i = 0; i < 6; i++) {
		if(grid1[a][0] == grid2[i][0] && !r1) r1++;
		if(grid1[b][1] == grid2[i][1] && !r2) r2++;
		if(grid1[c][2] == grid2[i][2] && !r3) r3++;
		if(grid1[d][3] == grid2[i][3] && !r4) r4++;
		if(grid1[e][4] == grid2[i][4] && !r5) r5++;
		sum = r1+r2+r3+r4+r5;
		if(sum == 5) return true;
	}
	return false;
}

void clone(int a, int b, int c, int d, int e) { ans[0] = grid1[a][0]; ans[1] = grid1[b][1]; ans[2] = grid1[c][2]; ans[3] = grid1[d][3]; ans[4] = grid1[e][4]; }

void backtrack(int k) {
	int cont = 0;
	for(int A = 0; A < 6; A++) {
		if(A != 0 && grid1[A][0] == grid1[A-1][0]) continue;
		for(int B = 0; B < 6; B++) {
			if(B != 0 && grid1[B][1] == grid1[B-1][1]) continue;
			for(int C = 0; C < 6; C++) {
				if(C != 0 && grid1[C][2] == grid1[C-1][2]) continue;
				for(int D = 0; D < 6; D++) {
					if(D != 0 && grid1[D][3] == grid1[D-1][3]) continue;
					for(int E = 0; E < 6; E++) {
						if(E != 0 && grid1[E][4] == grid1[E-1][4]) continue;	
						if(bb(A,B,C,D,E)) cont++;
						if(cont == k) {
							clone(A,B,C,D,E);	
							return;
						}
					}
				}
			}
		}
	}
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int k;
		scanf("%d",&k);
		for(int i = 0; i < 6; i++) scanf("%s",grid1[i]);
		for(int i = 0; i < 6; i++) scanf("%s",grid2[i]);
		T_sort();
		strcpy(ans,"Bateu");
		backtrack(k);
		(strcmp(ans,"Bateu")) ? printf("%s\n",ans) : printf("NO\n");
	}
}
