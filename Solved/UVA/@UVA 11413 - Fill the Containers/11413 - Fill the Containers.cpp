//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2408

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

bool check(int n, int qt_v, int qt_c, int arr[]) {
	int sum = 0, qt_ele = 1;
	for(int i = 0; i < qt_v; i++) {
		if(arr[i] > n) return false;
		sum += arr[i];
		if(sum > n) {
			sum = arr[i];
			qt_ele++;
			if(qt_ele > qt_c) return false;
		}
	}
	return true;
}

int bb(int qt_v, int qt_c, int best, int arr[]) {
	int left = 0, right = best, mid = 0;
	while(left+1 < right) {
		mid = (left+right)/2;
		check(mid,qt_v,qt_c,arr) ? right = mid : left = mid;
	}
	return right;
}

int main() {
	int qt_v, qt_c;
	while(scanf("%d %d",&qt_v,&qt_c) != EOF) {
		int arr[qt_v], best = 0;
		for(int i = 0 ; i < qt_v; i++) {
			scanf("%d",&arr[i]);
			best += arr[i];
		}
		printf("%d\n",bb(qt_v,qt_c,best,arr));
	}
}
