//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1768

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int maxSum(int n, int *m[]) {
	int ans = -1e9;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
		for(int k = i; k < i+n; k++) for(int l = j; l < j+n; l++) {
			int sb = m[k][l];
			if(i > 0) sb -= m[i-1][l];
			if(j > 0) sb -= m[k][j-1];
			if(i > 0 && j > 0) sb += m[i-1][j-1];
			ans = max(ans,sb);	
		}
	return ans;
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		int n;
		scanf("%d",&n);
		int *m[2*n];
		for(int i = 0; i < 2*n; i++) m[i] = new int[2*n];
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
			scanf("%d",&m[i][j]);
		for(int i = 0, x = n; i < 2*n; i++, x++) for(int j = 0, y = n; j < 2*n; j++, y++) {
			int &ret = m[i][j];
			if(i < n && j < n) m[x][j] = m[i][y] = m[x][y] = ret;
			if(i > 0) ret += m[i-1][j];
			if(j > 0) ret += m[i][j-1];
			if(i > 0 && j > 0) ret -= m[i-1][j-1];
		}

		int ans = maxSum(n,m);

		printf("%d\n",ans);
	}
}
