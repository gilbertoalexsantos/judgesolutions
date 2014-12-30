//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1842

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct date {
	int index;
	int arrive;
};

int debug;
queue<date> le, rg;
queue<date> ferry;
int ans[10001];
int cases, n, t, m;

void ll(int &tt) {
	queue<date> ferry;
	while(!le.empty()) {
		while(!le.empty() && le.front().arrive <= tt && ferry.size() < n) {
			ferry.push(le.front());
			le.pop();
		}
		tt += t;
		while(!ferry.empty()) {
			ans[ferry.front().index] = tt;
			ferry.pop();
		}
		break;
	}
}

void rr(int &tt) {
	queue<date> ferry;
	while(!rg.empty()) {
		while(!rg.empty() && rg.front().arrive <= tt && ferry.size() < n) {
			ferry.push(rg.front());
			rg.pop();
		}
		tt += t;
		while(!ferry.empty()) {
			ans[ferry.front().index] = tt;
			ferry.pop();
		}
		break;
	}
}

bool check(int side, int tt) {
	if(side && !le.empty() && le.front().arrive <= tt) return 1;
	if(!side && !rg.empty() && rg.front().arrive <= tt) return 0;
	if(rg.empty()) return 1;
	if(le.empty()) return 0;
	if(le.front().arrive < rg.front().arrive) return 1;
	else if(le.front().arrive > rg.front().arrive) return 0;
	else return side;
}

void load() {
	int tt = 0;
	bool side = 1;
	while(!le.empty() || !rg.empty()) {
		bool next = check(side, tt);
		//printf("SIDE: %d\nNext: %d\nLeft Size: %d\nRight Size: %d\nTempo - %d\n\n",side,next,le.size(),rg.size(),tt);
		//cin >> debug;
		if(next) {
			if(le.front().arrive > tt) {
				tt += le.front().arrive - tt;
				continue;
			}
		} else {
			if(rg.front().arrive > tt) {
				tt += rg.front().arrive - tt;
				continue;
			}
		}

		if(side != next) {
			tt += t;
			side = next;
			continue;
		}

		if(next) {
			ll(tt);
			side = 0;
		} else {
			rr(tt);
			side = 1;
		}
	}
}

void clear() {
	while(!rg.empty()) rg.pop();
	while(!le.empty()) le.pop();
	memset(ans,0,sizeof ans);
}

int main() {
	scanf("%d",&cases);
	while(cases--) {
		clear();
		scanf("%d %d %d",&n, &t, &m);
		for(int i = 0; i < m; i++) {
			date temp;
			string x;
			cin >> temp.arrive >> x;
			temp.index = i;
			if(x == "left") le.push(temp);
			else rg.push(temp);
		}
		load();
		for(int i = 0; i < m; i++) printf("%d\n",ans[i]);
		if(cases) printf("\n");
	}
}
