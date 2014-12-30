//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool bt(int pos, int sum, int n, int arr[], int size) {
	if(sum == n) return true;
	if(pos >= size || sum > n) return false;


	return bt(pos+1,sum+arr[pos],n,arr,size) || bt(pos+1,sum,n,arr,size);
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		int wanted, qt_bar;
		scanf("%d %d",&wanted,&qt_bar);
		int arr[qt_bar];
		for(register int i = 0; i < qt_bar; i++) scanf("%d",&arr[i]);
		if(bt(0,0,wanted,arr,qt_bar)) printf("YES\n");
		else printf("NO\n");
	}
}
