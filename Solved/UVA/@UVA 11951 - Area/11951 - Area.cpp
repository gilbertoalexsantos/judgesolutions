//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3102

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int,ll> pint;

ll matrix[100][100];

bool comp(pint a, pint b) {
	if(a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

pint dp(int l, int c, ll number) {
	pint ans(0,0);

	for(int i = 0; i < c; i++) for(int j = i; j < c; j++) {
		pint flag(0,0);
		int flag_ele = 0, last = 0;
		for(int row = 0; row < l; row++) {
			flag.second += matrix[row][j];
			flag.second -= (i > 0) ? matrix[row][i-1] : 0;

			if(flag.second > number) {
				while(flag.second > number && last <= row) {
					flag.second -= matrix[last][j];
					flag.second += (i > 0) ? matrix[last][i-1] : 0;
					last++;
				}
			}

			int qt_ele = (row-last+1)*(j-i+1);
			flag.first = qt_ele;

			if(comp(flag,ans)) ans = flag;
		}
	}

	return ans;
}

int main() {
	int cases = 1, T;
	scanf("%d",&T);
	while(T--) {
		int n, m;
		ll k;
		scanf("%d %d %lld",&n,&m,&k);
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
			scanf("%lld",&matrix[i][j]);
			ll &ret = matrix[i][j];
			if(j > 0) ret += matrix[i][j-1];
		}
		pint ans = dp(n,m,k);
		printf("Case #%d: %d %lld\n",cases++,ans.first,ans.second);
	}
}

