//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2445

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int dp(int bag, int qt_garment, int *price[]) {
	bool memo[qt_garment][bag+1];
	memset(memo,0,sizeof memo);

	for(int i = 1; i <= price[0][0]; i++) if(bag - price[0][i] >= 0)
		memo[0][bag - price[0][i]] = true;

	for(int i = 1; i < qt_garment; i++)
		for(int p = 0; p <= bag; p++) if(memo[i-1][p])
			for(int qt = 1; qt <= price[i][0]; qt++) if(p - price[i][qt] >= 0)
				memo[i][p - price[i][qt]] = true;

	int first = -1;
	for(int i = 0; i <= bag; i++) {
		if(memo[qt_garment-1][i]) {
			first = i;
			break;
		}
	}
	return first < 0 ? first : bag - first;
}

int main() {
	int n;
	scanf("%d",&n);
	while(n--) {
		int qt_money, qt_garment;
		scanf("%d %d",&qt_money,&qt_garment);
		int *arr_garment[qt_garment];
		for(int i = 0; i < qt_garment; i++) arr_garment[i] = new int[22];
		for(int i = 0; i < qt_garment; i++) {
			scanf("%d",&arr_garment[i][0]);
			for(int j = 1; j <= arr_garment[i][0]; j++) scanf("%d",&arr_garment[i][j]);
		}
		int ans = dp(qt_money,qt_garment,arr_garment);
		ans < 0 ? printf("no solution\n") : printf("%d\n",ans);
	}
}
