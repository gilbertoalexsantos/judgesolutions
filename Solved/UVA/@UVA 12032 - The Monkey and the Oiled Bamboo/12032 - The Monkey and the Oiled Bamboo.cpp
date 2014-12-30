//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3183

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool check(int k, int size, int arr[]) {
	for(int i = 0; i < size; i++) {
		if(!i) {
			if(k < arr[i]) return false;
			if(k == arr[i]) k--;
		} else {
			if(k < arr[i]-arr[i-1]) return false;
			if(k == arr[i] - arr[i-1]) k--;
		}
	}
	return true;
}

int bb(int size, int arr[]) {
	int left = 0, right = arr[size-1], mid = 0;
	while(left+1 < right) {
		mid = (left+right)/2;
		check(mid,size,arr) ? right = mid : left = mid;
	}
	return right;
}

int main() {
	int qt_cases, cases = 1;
	scanf("%d",&qt_cases);
	while(qt_cases--) {
		int qt_rung;
		scanf("%d",&qt_rung);
		int arr[qt_rung];
		for(int i = 0; i < qt_rung; i++) scanf("%d",&arr[i]);
		printf("Case %d: %d\n",cases++,bb(qt_rung,arr));
	}
}
