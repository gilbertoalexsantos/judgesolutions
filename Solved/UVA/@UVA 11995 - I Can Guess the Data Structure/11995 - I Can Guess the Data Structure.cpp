//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

int n;


int main() {
	while(scanf("%d",&n) != EOF) {
		int a, b;
		bool is_s, is_q, is_pq;
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		is_s = is_q = is_pq = true;
		for(int i = 0; i < n; i++) {
			scanf("%d %d",&a, &b);
			if(a == 1) {
				if(is_s) s.push(b);
				if(is_q) q.push(b);
				if(is_pq) pq.push(b);
			} else {
				if(is_s) {
					if(s.empty()) is_s ^= is_s;
					else if(s.top() == b) s.pop();
					else is_s ^= is_s;
				}
				if(is_q) {
					if(q.empty()) is_q ^= is_q;
					else if(q.front() == b) q.pop();
					else is_q ^= is_q;
				}
				if(is_pq) {
					if(pq.empty()) is_pq ^= is_pq;
					else if(pq.top() == b) pq.pop();
					else is_pq ^= is_pq;
				}
			}
		}
		int ans = is_s + is_q + is_pq;
		if(!ans) printf("impossible\n");
		else if(ans > 1) printf("not sure\n");
		else {
			if(is_s) printf("stack\n");
			else if(is_q) printf("queue\n");
			else printf("priority queue\n");
		}
	}
}
