//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1113

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

#define MAX 101

int debug;
int set, N, S, Q, ans;
bool cont;
stack<int> c;
queue<int> q[MAX];

void load(int station) {
	while(c.size() < S && !q[station].empty()) {
		ans += 1;
		c.push(q[station].front());
		q[station].pop();
	}
}

void unload(int station) {
	while(!c.empty()) {
		if(c.top() == station) {
			ans += 1;
			c.pop();
		} else if(q[station].size() < Q) {
			ans += 1;
			q[station].push(c.top());
			c.pop();
		} else break;
	}
}

void moveStation(int &station) {
	ans += 2;
	if(station == N) station = 1;
	else station++;
}

void clear() {
	ans = 0;
	cont = false;
	while(!c.empty()) c.pop();
	for(int i = 0; i < N+1; i++)
		while(!q[i].empty()) q[i].pop();
}

int main() {
	scanf("%d",&set);
	while(set--) {
		clear();
		scanf("%d %d %d",&N, &S, &Q);
		for(int i = 1; i <= N; i++) {
			int qt;
			scanf("%d",&qt);
			for(int j = 0; j < qt; j++) {
				int temp;
				scanf("%d",&temp);
				q[i].push(temp);
			}
		}
		int station = 1;
		while(!c.empty() || !cont) {
			unload(station);
			load(station);
			moveStation(station);
			cont = true;
			for(int i = 1; i < N; i++)
				if(!q[i].empty()) cont = false;
		}
		// -2 because the last "moveStation"... It only checks if
		// have finished the problem after the "moveStation", so the algorithm
        // does a useless "moveStation"
		printf("%d\n",ans - 2);
	}
}
