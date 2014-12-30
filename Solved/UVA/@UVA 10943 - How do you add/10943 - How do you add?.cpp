//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1884

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MOD 1000000

int memo[101][100];

int dp(int n, int k, int pos = 0, int value = 0) {
	if(pos == k) return value == n;
	if(value > n) return 0;

	int &ret = memo[value][pos];
	if(ret != -1) return ret;

	ret = 0;
	for(int i = 0; i <= n; i++) ret += dp(n,k,pos+1,value + i) % MOD;
	return ret % MOD;
}

int main() {
	int n, k;
	while(scanf("%d %d",&n,&k) && n+k) {
		memset(memo,-1,sizeof memo);
		int ans = dp(n,k);
		printf("%d\n",ans);
	}
}
