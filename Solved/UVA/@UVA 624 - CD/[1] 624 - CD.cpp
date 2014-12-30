//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=565

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
using namespace std;

int flag_sum;
bool flag[20], visited[20];

void bt(int pos, int wanted, int size, int arr[], int sum = 0) {
	if(pos == size) {
		int value = wanted - sum;
		if(value >= 0 && value < flag_sum) {
			flag_sum = value;
			for(register int i = 0; i < size; i++) flag[i] = visited[i];
		}
		return;
	}

	visited[pos] = 1;
	bt(pos+1,wanted,size,arr,sum+arr[pos]);
	visited[pos] = 0;
	bt(pos+1,wanted,size,arr,sum);
}

void clear(int n) {
	for(register int i = 0; i < n; i++) {
		visited[i] = 0;
		flag[i] = 0;
	}
	flag_sum = 1e9;
}

int main() {
	int wanted;
	while(scanf("%d",&wanted) != EOF) {
		int qt_track;
		scanf("%d",&qt_track);

		clear(qt_track);

		int arr[qt_track];
		for(register int i = 0; i < qt_track; i++) scanf("%d",&arr[i]);

		bt(0,wanted,qt_track,arr);

		int sum = 0;
		for(register int i = 0; i < qt_track; i++) {
			if(flag[i]) {
				printf("%d ",arr[i]);
				sum += arr[i];
			}
		}
		printf("sum:%d\n",sum);
	}
}
