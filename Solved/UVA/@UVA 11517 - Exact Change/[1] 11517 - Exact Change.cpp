//Author:	Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2512

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef pair<int,int> pint;

const int MAX_COIN = 100;
const int MAX_VALUE = 10001;
const int INF = 1e9;

pint memo[MAX_VALUE][MAX_COIN];
int arr_coin[MAX_COIN];
int n, k;

pint dp(int pos = 0, int left = n) {
	if(left <= 0) return pint(0,0);
	if(pos >= k) return pint(INF,INF);

	pint &ret = memo[left][pos];
	if(ret.first != -1) return ret;

	// GET coin
	pint d1 = dp(pos+1,left - arr_coin[pos]);
	d1.first += arr_coin[pos];
	d1.second++;

	// PASS coin
	pint d2 = dp(pos+1,left);

	return ret = min(d1,d2);
}

void clear() {
	for(int i = 0; i < MAX_VALUE; i++) for(int j = 0; j < k; j++) 
		memo[i][j] = pint(-1,-1);
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		scanf("%d %d",&n,&k);
		clear();
		for(int i = 0; i < k; i++) scanf("%d",&arr_coin[i]);
		pint ans = dp();
		printf("%d %d\n",ans.first,ans.second);
	}
}
