//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF 1000000000

bool visited[50];
int memo[1000][1000];

inline bool check(int n, int left, int right) { return (n >= left && n <= right); }

int dp(int left, int right, int size, int arr[], int qt = 0) {
	if(qt == size) return 0;

	int &ret = memo[left][right];
	if(ret != -1) return ret;

	ret = INF;
	for(int i = 0; i < size; i++) {
		if(visited[i] || !check(arr[i],left,right)) continue;
		visited[i] = true;
		int p1 = dp(left,arr[i],size,arr,qt+1);
		int p2 = dp(arr[i],right,size,arr,qt+1);
		int c = right - left;
		if(p1 == INF) p1 = 0;
		if(p2 == INF) p2 = 0;
		visited[i] = false;
		ret = min(ret,p1+p2+c);
	}

	return ret;
}

void clear() {
	memset(memo,-1,sizeof memo);
	memset(visited,0,sizeof visited);
}

int main() {
	int l;
	while(scanf("%d",&l) && l) {
		clear();

		int qt_cut;
		scanf("%d",&qt_cut);
		int arr_cut[qt_cut];
		for(int i = 0; i < qt_cut; i++) scanf("%d",&arr_cut[i]);

		int ans = dp(0,l,qt_cut,arr_cut);

		printf("The minimum cutting is %d.\n",ans);
	}
}
