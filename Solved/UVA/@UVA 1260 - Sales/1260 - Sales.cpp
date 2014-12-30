//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3701

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int getMin(int pos, int arr[]) {
	int ans = 0;
	for(int i = 0; i < pos; i++) if(arr[i] <= arr[pos]) ans++; 
	return ans;
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
		int ans = 0;
		for(int i = 1; i < n; i++) ans += getMin(i,arr);
		printf("%d\n",ans);
	}
}
