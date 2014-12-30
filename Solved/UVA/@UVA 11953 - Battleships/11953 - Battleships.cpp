//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3104

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const char EMPTY = '.', SHIP = 'x', HIT = '@';
const int dr[4] = {0,1, 0,-1};
const int dc[4] = {1,0,-1, 0};

int size;
char m[101][101];

void dfs(int x, int y) {
	if(x < 0 || x >= size || y < 0 || y >= size || m[x][y] == EMPTY) return;
	m[x][y] = EMPTY;
	for(int i = 0; i < 4; i++) dfs(x+dr[i],y+dc[i]);
}

int main() {
	int T, cases = 1;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&size);
		for(int i = 0; i < size; i++) scanf("%s",m[i]);
		int ans = 0;
		for(int i = 0; i < size; i++) for(int j = 0; j < size; j++)
			if(m[i][j] == SHIP) dfs(i,j), ans++;
		printf("Case %d: %d\n",cases++,ans);
	}
}
