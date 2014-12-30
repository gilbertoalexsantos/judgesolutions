//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3086

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

#define EPS 1e-9

struct type {
	int pos,con;
	char t[20];
};

bool can(double fuel, queue<type> q) {
	double leak = 0.0, first_fuel = fuel, consume = 0.0;
	int last_pos = 0;
	while(!q.empty()) {
		type t = q.front();
		double p = (double) (t.pos-last_pos)/100.0;

		if(t.pos != last_pos) fuel = fuel - p*(consume+leak);
		if(fuel < EPS) return false;

		if(t.t[0] == 'F') consume = (double) t.con;
		else if(t.t[0] == 'L') leak += 100.0;
		else if(t.t[0] == 'M') leak = 0.0;
		else if(t.t[0] == 'G' && t.t[1] == 'a') fuel = first_fuel;

		last_pos = t.pos;
		q.pop();
	}
	return true;
}

double ans(queue<type>  &q) {
	double left = 0.0, right = 10000.0, mid = 0.0, ret = 0.0;
	while(fabs(right - left) > EPS) {
		mid = (right+left)/2.0;
		if(can(mid,q)) ret = mid, right = mid;
		else left = mid;
	}
	return ret;
}

int main() {
	type t;
	queue<type> q;
	while(scanf("%d %16[^\n]s",&t.pos,t.t)) {
		if(t.t[0] == 'F') scanf("%d",&t.con);
		if(!(t.pos+t.con)) return 0;
		q.push(t);
		if(t.t[0] == 'G' && t.t[1] == 'o') {
			printf("%.3lf\n",ans(q));
			while(!q.empty()) q.pop();
		}
	}
}
