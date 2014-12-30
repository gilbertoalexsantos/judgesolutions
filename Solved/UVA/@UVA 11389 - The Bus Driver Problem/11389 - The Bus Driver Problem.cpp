//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2384

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int solve(int n, int d, int r, int arr_m[], int arr_e[]) {
	sort(arr_m,arr_m + n), sort(arr_e,arr_e + n);
	int left = 0, right = n-1, ans = 0;
	while(right >= 0) {
		int to_sum = (arr_m[left] + arr_e[right]) - d;
		if(to_sum > 0) ans += r * to_sum;
		left++, right--;
	}
	return ans;
}

int main() {
	int n, d, r;
	while(scanf("%d %d %d",&n,&d,&r) && n+d+r) {
		int arr_morning[n], arr_evening[n];
		for(int i = 0; i < n; i++) scanf("%d",&arr_morning[i]);
		for(int i = 0; i < n; i++) scanf("%d",&arr_evening[i]);
		printf("%d\n",solve(n,d,r,arr_morning,arr_evening));
	}
}
