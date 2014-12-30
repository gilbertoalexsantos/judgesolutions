//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1998

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> pint;

pint solve(int k, int arr[], int size) {
	sort(arr,arr+size);
	pint ans(0,1e9);
	for(int i = 0; i < size; i++) {
		int v1 = arr[i];
		int left = i+1, right = size-1, mid = 0;
		while(left <= right) {
			mid = (left+right)/2;
			int v2 = arr[mid];	
			if(v1 + v2 == k && abs(v1-v2) < abs(ans.first-ans.second))
				ans.first = v1, ans.second = v2;
			if(v1 + v2 < k) left = mid+1;
			else right = mid-1;
		}
	}
	return ans;
}

int main() {
	int n;
	while(scanf("%d",&n) != EOF) {
		int arr[n], k;
		for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
		scanf("%d",&k);
		pint ans = solve(k,arr,n);
		printf("Peter should buy books whose prices are %d and %d.\n\n",ans.first,ans.second);
	}
}
