//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1597

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;


int main() {
	int n;
	while(scanf("%d",&n) && n) {
		vector<int> ans;
		for(int i = 0; i < n; i++) {
			int t;
			scanf("%d",&t);
			if(t) ans.push_back(t);
		}
		if(ans.empty()) printf("0\n");
		else {
			printf("%d",ans[0]);
			for(int i = 1; i < ans.size(); i++) printf(" %d",ans[i]);
			printf("\n");
		}
	}
}
