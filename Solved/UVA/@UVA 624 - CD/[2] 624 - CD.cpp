//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=565

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

int knapsack(int arr[], int size, int wanted) {
	int knap[size][wanted+1];
	memset(knap,0,sizeof knap);

	for(register int i = 0; i <= wanted; i++)
		if(i >= arr[0]) knap[0][i] = arr[0];

	int line = size-1, col = wanted;
	for(register int i = 1; i < size; i++) {
		for(register int j = 0; j <= wanted; j++) {
			knap[i][j] = knap[i-1][j];
			if(j - arr[i] >= 0) knap[i][j] = max(knap[i][j],knap[i-1][j - arr[i]] + arr[i]);
		}
		if(knap[i][wanted] == wanted) {
			line = i;
			break;
		}
	}
	
	int line_resp = line;
	stack<int> ans;
	while(line > 0 && knap[line][col] == knap[line-1][col]) line--;
	while(1) {
		if(!line) {
			if(col - arr[line] >= 0) ans.push(arr[line]);
			break;
		}
		if(col - arr[line] < 0) {
			line--;
			continue;
		}
		if(knap[line-1][col-arr[line]] + arr[line] == knap[line][col]) {
			ans.push(arr[line]);
			col -= arr[line--];
		} else line--;
	}
	while(!ans.empty()) {
		printf("%d ",ans.top());
		ans.pop();
	}

	return knap[line_resp][wanted];
}

int main() {
	int wanted;
	while(scanf("%d",&wanted) != EOF) {
		int qt_track;
		scanf("%d",&qt_track);
		int arr[qt_track];
		for(register int i = 0; i < qt_track; i++) scanf("%d",&arr[i]);
		int sum = knapsack(arr,qt_track,wanted);
		printf("sum:%d\n",sum);
	}
}

