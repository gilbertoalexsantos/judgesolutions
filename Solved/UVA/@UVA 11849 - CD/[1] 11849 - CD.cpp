//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2949

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int arr[1000000];
int n, m;

int main() {
	while(scanf("%d %d",&n, &m) && !(!n && !m)) {
		int ans = 0;
		for(int i = 0; i < n; i++) scanf("%d",&arr[i]);

		int pointer = 0;
		for(int i = 0; i < m; i++) {
			int t;
			scanf("%d",&t);
			while(arr[pointer] < t && pointer < n) pointer++;
			if(pointer < n) if(arr[pointer] == t) ans++;
		}
		printf("%d\n",ans);
	}
}
