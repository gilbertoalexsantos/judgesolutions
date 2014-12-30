//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1975

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;


int cases, ferry_size, qt_cars, actual_size;
queue<int> cars_left;
queue<int> cars_right;
queue<int> ferry;

int debug; 

void load(bool side) {
	if(side) {
		while(!cars_left.empty()) {
			if(actual_size + cars_left.front() > ferry_size) break;
			actual_size += cars_left.front();
			ferry.push(cars_left.front());
			cars_left.pop();
		}
	} else {
		while(!cars_right.empty()) {
			if(actual_size + cars_right.front() > ferry_size) break;
			actual_size += cars_right.front();
			ferry.push(cars_right.front());
			cars_right.pop();
		}
	}
}

void unload(bool side) {
	while(!ferry.empty()) {
		actual_size -= ferry.front();
		ferry.pop();
	}
}

void change(bool &side, int &n) {
	side = !side;
	n++;
}

int main() {
	scanf("%d",&cases);
	while(cases--) {
		scanf("%d %d",&ferry_size, &qt_cars);
		ferry_size = ferry_size * 100;
		for(int i = 0; i < qt_cars; i++) {
			int temp;
			char side[6];	
			scanf("%d %s",&temp,side);
			if(side[0] == 'l') cars_left.push(temp);
			else cars_right.push(temp);
		}
		bool side = 1;
		int ans = 0;
		actual_size = 0;
		while(!cars_left.empty() || !cars_right.empty() || !ferry.empty()) {
			load(side);
			change(side,ans);
			unload(side);
		}
		printf("%d\n",ans);
	}
}
