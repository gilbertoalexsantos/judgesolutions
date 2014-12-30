//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1557

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;
ll memo[200][40][10];

ll dp(int d, int m, int size, int arr[], int pos = 0, int pos_m = 0, int value = 0) {
	if(pos_m == m) return (value == 0);
	if(pos == size || pos_m+(size-pos) < m) return 0;

	ll &ret = memo[pos][(value < 0) ? (-value+20) : value][pos_m];
	if(ret != -1) return ret;

	ret = 0;
	int d1 = value%d;
	int d2 = (d1 + (arr[pos]%d)) % d;
	ret += dp(d,m,size,arr,pos+1,pos_m,d1);
	ret += dp(d,m,size,arr,pos+1,pos_m+1,d2);

	return ret;
}

int main() {
	int n, q, cases = 1;
	while(scanf("%d %d",&n,&q) && n+q) {
		int arr[n];
		for(int i = 0; i < n ; i++) scanf("%d",&arr[i]);
		printf("SET %d:\n",cases++);
		for(int i = 1; i <= q; i++) {
			memset(memo,-1,sizeof memo);
			int d, m;
			scanf("%d %d",&d,&m);
			ll ans = (m > n) ? 0 : dp(d,m,n,arr);
			printf("QUERY %d: %lld\n",i,ans);
		}
	}
}
