//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1247

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef pair<int,int> pint;

inline int calc_n(pint a) { return a.first*a.first+a.second*a.second; }
inline bool check(pint a, int s) { return calc_n(a) == s*s; }

int memo[301][301][41];
int arr_coin[41], arr_info[41];

int dp(int size, int s, pint value, int pos = 0, int qt_coin = 0) {
	if(calc_n(value) > s*s) return 1e9;
	if(pos == size) return check(value,s) ? qt_coin : 1e9;

	int &ret = memo[value.first][value.second][pos];
	if(ret != -1) return ret;
	ret = 1e9;

	pint t1(value.first,value.second);
	pint t2(value.first+arr_coin[pos],value.second+arr_info[pos]);
	int d1 = dp(size,s,t1,pos+1,qt_coin);
	int d2 = dp(size,s,t2,pos,qt_coin+1);

	return ret = min(d1,d2);
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		memset(memo,-1,sizeof memo);
		int m, s;
		scanf("%d %d",&m,&s);
		for(int i = 0; i < m; i++) scanf("%d %d",&arr_coin[i],&arr_info[i]);
		pint t(0,0);
		int ans = dp(m,s,t);
		ans != 1e9 ? printf("%d\n",ans) : printf("not possible\n");
	}
}
