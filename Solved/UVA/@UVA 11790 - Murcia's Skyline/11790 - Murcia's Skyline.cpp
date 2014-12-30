//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2890

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> pint;
typedef vector<pint> vi;

int main() {
	int T, cases = 1;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		vi arr(n);
		for(int i = 0; i < n; i++) scanf("%d",&arr[i].first);
		for(int i = 0; i < n; i++) scanf("%d",&arr[i].second);

		int lis[n], lds[n], lis_max = -1e9, lds_max = -1e9;
		for(int i = 0; i < n; i++) lis[i] = lds[i] = arr[i].second;

		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				if(arr[j].first > arr[i].first && lis[j] - arr[j].second < lis[i]) lis[j] = lis[i] + arr[j].second;
				if(arr[j].first < arr[i].first && lds[j] - arr[j].second < lds[i]) lds[j] = lds[i] + arr[j].second;
				lis_max = max(lis_max,lis[i]);
				lds_max = max(lds_max,lds[i]);
			}
		}

		pint ans;
		bool e_lis = false;
		ans.first = max(lis_max,lds_max);
		ans.second = min(lis_max,lds_max);
		e_lis = lis_max >= lds_max;

		char w[2][12];
		strcpy(w[0],"Decreasing");
		strcpy(w[1],"Increasing");

		printf("Case %d. %s (%d). %s (%d).\n",cases++,w[e_lis],ans.first,w[!e_lis],ans.second);
	}
}
