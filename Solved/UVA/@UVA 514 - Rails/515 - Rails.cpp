//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

int n;

int main() {
	while(scanf("%d",&n) && n) {
		stack<int> rail;
		queue<int> train;
		bool loop = true;
		while(loop) { 
			for(int i = 1; i <= n; i++) { 
				int temp;
				scanf("%d",&temp); 
				if(!temp) { loop = false; break; }
				rail.push(i);
				train.push(temp); 
				while(!train.empty() && !rail.empty() && train.front() == rail.top()) {
					train.pop();
					rail.pop();
				}
			}
			if(loop) {
				if(train.empty() && rail.empty()) printf("Yes\n");
				else printf("No\n");
				while(!rail.empty()) rail.pop();
				while(!train.empty()) train.pop();
			}
		}
		printf("\n");
	}
}
