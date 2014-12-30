//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1428

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void getSums(vector<int> &sum, int arr[], int size) {
	for(int i = 0; i < size; i++)
		for(int j = i+1; j < size; j++)
			if(arr[i] != arr[j]) sum.push_back(arr[i] + arr[j]);
	sort(sum.begin(),sum.end());
}

int getAns(vector<int> &sum, int number) {
	int ans = -1;
	for(int i = 0; i < sum.size(); i++) {
		if(sum[i] <= number) ans = sum[i];
		else {
			if(ans == -1) return sum[i];
			else {
				int p1 = number - ans;
				int p2 = sum[i] - number;
				return (p1 < p2) ? ans : sum[i];
			}
		}
	}
	return ans;
}

int main() {
	int n;
	int qt_cases = 1;
	while(scanf("%d",&n) && n) {
		int arr[n];
		for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
		vector<int> sum;
		getSums(sum,arr,n);
		int m;
		printf("Case %d:\n",qt_cases++);
		scanf("%d",&m);
		while(m--) {
			int query;
			scanf("%d",&query);
			printf("Closest sum to %d is %d.\n",query,getAns(sum,query));
		}
	}
}
