//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3344

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int lower_b(int k, int l, int r, int row, int *m[]) {
	int left = l, right = r, mid = 0, ans = -1;
	while(left <= right) {
		mid = (left+right)/2;
		if(m[row][mid] <= k) ans = mid, left = mid+1;
		else right = mid-1;
	}
	return ans;
}

int first_ocorrence(int k, int l, int r, int row, int *m[]) {
	int left = l, right = r, mid = 0, ans = -1;
	while(left <= right) {
		mid = (left+right)/2;
		if(m[row][mid] >= k) ans = mid, right = mid-1;
		else left = mid+1;
	}
	return ans;
}

int solve(int L, int U, int row, int col, int *m[]) {
	int ans = 0;
	for(int i = 0; i < row; i++) {
		int start = first_ocorrence(L,0,col-1,i,m), finish = lower_b(U,0,col-1,i,m);
		if(start == -1 || finish == -1 || finish < start) continue;
		if(finish-start+1 < ans) continue;
		while(finish >= start) {
			int qt = finish-start;
			if(qt+1 < ans) break;
			if(i+qt >= row) {
				finish--;
				continue;
			}
			if(m[i+qt][finish] <= U) ans = max(ans,qt+1);
			finish--;
		}
	}
	return ans;
}

int main() {
	int n, m;
	while(scanf("%d %d",&n, &m) && n+m) {
		int *matrix[n];
		for(int i = 0; i < n; i++) {
			matrix[i] = new int[m];
			for(int j = 0; j < m; j++) scanf("%d",&matrix[i][j]);
		}
		int qt_querie;
		scanf("%d",&qt_querie);
		while(qt_querie--) {
			int L, U;
			scanf("%d %d",&L,&U);
			printf("%d\n",solve(L,U,n,m,matrix));
		}
		printf("-\n");
	}
}
