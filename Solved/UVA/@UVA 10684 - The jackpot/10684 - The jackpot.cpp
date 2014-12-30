//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1625

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int dp(int n, int arr[]) {
	int sum = 0, flag = 0;
	for(int i = 0; i < n; i++) {
		flag += arr[i];
		if(flag < 0) flag = 0;
		sum = max(sum,flag);
	}
	return sum;
}

int main() {
	int n;
	while(scanf("%d",&n) && n) {
		int arr[n];
		for(int i = 0; i < n; i++) scanf("%d",&arr[i]);

		int ans = dp(n,arr);
		ans <= 0 ? printf("Losing streak.\n") : printf("The maximum winning streak is %d.\n",ans);
	}
}
