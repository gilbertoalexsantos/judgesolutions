//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2986

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 12;

int size;
int arr[MAX];

int main() {
	int cases = 1, T; scanf("%d",&T);
	while(T--) {
		scanf("%d",&size);
		for(int i = 0; i < size; i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+ + size);
		printf("Case %d: %d\n",cases++,arr[size / 2]);
	}
}
