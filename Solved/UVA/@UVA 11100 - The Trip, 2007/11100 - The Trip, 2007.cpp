//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2041

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

void solve(int size, int arr[]) {
	sort(arr,arr+size);
	int max_eq = 1, flag_eq = 1;
	for(int i = 1; i < size; i++) {
		(arr[i] == arr[i-1]) ? flag_eq++ : flag_eq = 1;
		max_eq = max(max_eq,flag_eq);
	}
	printf("%d\n",max_eq);
	for(int i = 0; i < max_eq; i++) {
		printf("%d",arr[i]);
		for(int j = i+max_eq; j < size; j += max_eq)
			printf(" %d",arr[j]);
		printf("\n");
	}
}

int main() {
	int n;
	bool first = true;
	while(scanf("%d",&n) && n) {
		first ? first = false : printf("\n");
		int arr_bag[n];
		for(int i = 0; i < n; i++) scanf("%d",&arr_bag[i]);
		solve(n,arr_bag);
	}
}
