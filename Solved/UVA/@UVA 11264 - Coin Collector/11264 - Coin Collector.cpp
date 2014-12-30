//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2231

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef unsigned long long ull;

ull solve(ull qt_coins, ull arr[]) {
	if(qt_coins <= 2) return qt_coins;
	int ans = 2, sum = 1;
	for(int i = 1; i < qt_coins-1; i++) if(sum < arr[i] && sum + arr[i] < arr[i+1]) 
		sum += arr[i], ans++;
	return ans;
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		ull qt_coins;
		scanf("%llu",&qt_coins);
		ull arr[qt_coins];
		for(ull i = 0; i < qt_coins; i++) scanf("%llu",&arr[i]);
		ull ans = solve(qt_coins,arr);
		printf("%llu\n",ans);
	}
}
