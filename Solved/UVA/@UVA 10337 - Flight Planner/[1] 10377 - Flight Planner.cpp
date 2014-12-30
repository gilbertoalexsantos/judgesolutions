//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1278

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int CLIMB = 60, HOLD = 30, SINK = 20;

int memo[1001][10];
int wind[10][1001];

int dp(int size, int pos = 0, int alt = 0) {
	if(pos == size) return alt ? 1e9 : 0;

	int &ret = memo[pos][alt];
	if(ret != -1) return ret;

	int v = -wind[alt][pos];

	int d1 = 1e9, d2 = 1e9, d3 = 1e9;

	//CLIMB
	if(alt != 9 && pos != size-1) 
		d1 = dp(size,pos+1,alt+1) + CLIMB+v;

	//HOLD
	if(pos != 0 && pos != size-1) 
		d2 = dp(size,pos+1,alt) + HOLD+v;

	//SINK
	if(pos == size-1 || (alt != 0 && pos != 0))
		d3 = dp(size,pos+1,alt-1) + SINK+v;

	return ret = min(d1,min(d2,d3));
}

int main() {
	int cases;
	scanf("%d",&cases);
	bool first = true;
	while(cases--) {
		memset(memo,-1,sizeof memo);
		int n;
		scanf("%d",&n);
		for(int i = 9; i >= 0; i--) for(int j = 0; j < n/100; j++) scanf("%d",&wind[i][j]);
		int ans = dp(n/100);
		printf("%d\n\n",ans);
	}
}
