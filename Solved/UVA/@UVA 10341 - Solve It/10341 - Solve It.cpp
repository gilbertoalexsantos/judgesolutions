//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1282

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define EPS 1e-5

typedef pair<double,double> pint;

int p, q, r, s, t, u;

inline double check(double x) { return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u; }

bool close0(double a, double b) {
	if(a >= 0 && b >= 0) return a < b;
	if(a < 0 && b <= 0) return a > b;
	return a < b;
}

double bb() {
	double left = 0, right = 1, mid = 0;
	while(fabs(left-right) > EPS) {
		mid = (left+right)/2;
		double cmid = check(mid), cright = check(right);
		if(close0(cmid,cright)) right = mid;
		else left = mid;
	}
	return mid;
}

bool haveSolution() {
	double left = check(0), right = check(1);
	if(left == 0 || right == 0) return true;
	return (left < 0) ? right > 0 : right < 0;
}

int main() {
	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u) != EOF) {
		if(!haveSolution()) printf("No solution\n");
		else printf("%.4f\n",bb());
	}
}
