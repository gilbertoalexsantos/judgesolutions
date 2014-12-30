//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2613

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	int n, x, t, k;
	while(scanf("%d %d %d %d",&n,&x,&t,&k) && n+x+t+k) {
		int arr_price[k], arr_favour[n+1][k];
		int total_dishe = 2*(n+1), sum = 0;
		for(int i = 0; i < k; i++) {
			scanf("%d",&arr_price[i]);
			for(int j = 0; j <= n; j++) scanf("%d",&arr_favour[j][i]);
		}
		
		int memo[x+1][3];
		memset(memo, 0, sizeof memo);
		memo[0][0] = 1;
		for(int i = 0; i < k*2; i++)
			for(int j = x; j >= arr_price[i%k]; j--) {
				int pos = j - arr_price[i%k];
				if(memo[pos][0]) {
					memo[j][0] = 1;
					for(int c = 0; c <= n; c++) {
						if(memo[j][1] < memo[pos][1] + arr_favour[c][i%k]) {
							if(memo[pos][2] + 1 <= total_dishe) {
								memo[j][1] = memo[pos][1] + arr_favour[c][i%k];
								memo[j][2] = memo[pos][2] + 1;
							}
						}
					}
				}
			}
		
		double ans = -1;
		for(int i = 0; i < x+1; i++) ans = max((int)ans,memo[i][1]);
		ans = (double) ans/(n+1);
		printf("%.2f\n",ans);
	}
}
