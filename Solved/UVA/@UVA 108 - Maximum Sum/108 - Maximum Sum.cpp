//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=44

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int m[100][100];

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			scanf("%d",&m[i][j]);
			if(i > 0) m[i][j] += m[i-1][j];
			if(j > 0) m[i][j] += m[i][j-1];
			if(i > 0 && j > 0) m[i][j] -= m[i-1][j-1];
		}

	int ans = -1e9;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
		for(int a = i; a < n; a++) for(int b = j; b < n; b++) {
			int temp = m[a][b];	
			if(i > 0) temp -= m[i-1][b];
			if(j > 0) temp -= m[a][j-1];
			if(i > 0 && j > 0) temp += m[i-1][j-1];
			ans = max(ans,temp);
		}

	printf("%d\n",ans);
}
