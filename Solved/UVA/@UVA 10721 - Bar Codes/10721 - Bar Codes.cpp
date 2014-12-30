//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1662

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;

int n, k, m;

ll memo[51][51][51];

ll dp(int pos = 1, int qt_bar = 1, int wide = 1, int lbit = 1) {
	if(qt_bar > k || wide > m) return 0;
	if(pos == n) return (qt_bar == k && wide <= m);

	ll &ret = memo[pos][qt_bar][wide];
	if(ret != -1) return ret;

	// Pegando bit '1'
	ll p1 = dp(pos+1,qt_bar+!lbit,lbit ? wide+1 : 1,1);
	
	// Pegando bit '0'
	ll p2 = dp(pos+1,qt_bar+lbit,lbit ? 1 : wide+1,0);

	return ret = p1+p2;
}

int main() {
	while(scanf("%d %d %d",&n,&k,&m) != EOF) {
		memset(memo,-1,sizeof memo);
		ll ans = dp();
		printf("%lld\n",ans);
	}
}
