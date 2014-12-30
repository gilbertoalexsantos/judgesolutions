//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2445

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF 1e9

int memo[21][201];

int dp(int value, int bag, int pos_garment, int qt_garment, int *arr_garment[]) {
	if(value < 0) return -INF;
	if(pos_garment >= qt_garment) return bag - value;
	int &ret = memo[pos_garment][value];
	if(ret != -1) return ret;
	for(int i = 1; i <= arr_garment[pos_garment][0]; i++)
		ret = max(ret,dp(value - arr_garment[pos_garment][i],bag,pos_garment+1,qt_garment,arr_garment));
	return ret;
}

int main() {
	int n;
	scanf("%d",&n);
	while(n--) {
		memset(memo,-1,sizeof memo);
		int qt_money, qt_garment;
		scanf("%d %d",&qt_money,&qt_garment);
		int *arr_garment[qt_garment];
		for(int i = 0; i < qt_garment; i++) arr_garment[i] = new int[22];
		for(int i = 0; i < qt_garment; i++) {
			int k;
			scanf("%d",&k);
			arr_garment[i][0] = k;
			for(int j = 1; j <= k; j++) scanf("%d",&arr_garment[i][j]);
		}
		int ans = dp(qt_money,qt_money,0,qt_garment,arr_garment);
		ans < 0 ? printf("no solution\n") : printf("%d\n",ans);
	}
}
