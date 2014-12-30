//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=422

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int main() {
	vector<int> arr;	
	int n;
	while(scanf("%d",&n) != EOF) arr.push_back(n);
	
	int lis = 0, lis_end = 0;
	int arr_lis[arr.size()], arr_pos[arr.size()], arr_id[arr.size()];
	for(int i = 0; i < arr.size(); i++) {
		int pos = lower_bound(arr_lis,arr_lis+lis,arr[i]) - arr_lis;
		arr_lis[pos] = arr[i];
		arr_id[pos] = i;
		arr_pos[i] = pos ? arr_id[pos-1] : -1;
		if(pos+1 > lis) {
			lis = pos+1;
			lis_end = i;
		}
	}

	printf("%d\n-\n",lis);

	int x = lis_end;
	stack<int> s;
	while(arr_pos[x] != -1) {
		s.push(arr[x]);
		x = arr_pos[x];
	}

	printf("%d\n",arr[x]);
	while(!s.empty()) {
		printf("%d\n",s.top());
		s.pop();
	}
}
