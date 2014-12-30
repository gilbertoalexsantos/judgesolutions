//Author:	Gilberto A. dos Santos
//Website:	http://www.spoj.com/problems/LINEUP/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int grid[11][11], memo[11][1 << 11];

int dp(int row, int mask) {
	if(row == 11) return 0;
	int &ret = memo[row][mask];
	if(ret >= 0) return ret;
	ret = -1e9;
	for(register int col = 0; col < 11; col++) {
		if(!grid[row][col] || (mask & (1 << col))) continue;
		ret = max(ret,grid[row][col] + dp(row+1,(mask | (1 << col))));
	}
	return ret;
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		memset(memo,-1,sizeof memo);
		for(register int i = 0; i < 11; i++)
			for(register int j = 0; j < 11; j++)
				scanf("%d",&grid[i][j]);
		printf("%d\n",dp(0,0));
	}
}
