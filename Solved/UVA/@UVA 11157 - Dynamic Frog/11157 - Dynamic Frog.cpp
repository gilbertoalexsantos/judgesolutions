//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2098

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, bool> pint;

char flag[1000000001];

int solve(int d, vector<pint> &arr) {
	int ans = -1;
	for(int i = 0; i < arr.size()-2; i++) {
		if(arr[i+1].second)
			ans = max(ans,max(arr[i+1].first-arr[i].first,arr[i+2].first-arr[i].first));
		else
			ans = max(ans,arr[i+1].first-arr[i].first);
	}
	ans = max(ans,arr[arr.size()-1].first - arr[arr.size()-2].first);
	return ans;
}

int main() {
	int cases = 1, T;
	scanf("%d",&T);
	while(T--) {
		int n, d;
		scanf("%d %d",&n,&d);
		vector<pint> arr;
		arr.push_back(pint(0,0));
		for(int i = 0; i < n; i++) {
			scanf("%s",flag);
			int t = atoi(flag + 2);
			pint temp;
			temp.first = t;
			temp.second = (flag[0] == 'S');
			arr.push_back(temp);
		}
		arr.push_back(pint(d,0));
		printf("Case %d: %d\n",cases++,solve(d, arr));
	}
}
