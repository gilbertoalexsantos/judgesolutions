//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1323

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define EPS 1e-9
#define trace(x...) 

inline bool equalThan(double a, double b) { return fabs(a - b) < EPS; }
inline bool differThan(double a, double b) { return fabs(a - b) > EPS; }
inline bool greaterThan(double a, double b) { return (a - b) > EPS; }
inline bool lessThan(double a, double b) { return (a - b) < EPS; }
inline bool greaterEqualZero(double a) { return a > -EPS; }
inline bool lessEqualZero(double a) { return a < EPS; }

struct POINT {
	double left, right;

	POINT(int x, int w, int r) {
		double dx = sqrt(pow(r,2) - pow(w/2.0,2));
		left = x - dx, right = x + dx;
	}
};

bool comp(POINT a, POINT b) {
	if(equalThan(a.left,b.left)) return greaterThan(a.right,b.right);
	return lessThan(a.left,b.left);
}

int solve(int l, vector<POINT> &arr) {
	int ans = 0;
	double max_r = 0;
	int begin = 0;
	while(greaterThan(l,max_r)) {
		double flag_r = 0;
		int i = 0;
		while(i < arr.size() && greaterEqualZero(max_r - arr[i].left)) {
			flag_r = max(flag_r,arr[i].right);
			i++;
		}
		if(greaterEqualZero(max_r - flag_r)) break;
		max_r = flag_r;
		ans++;
	}
	if(greaterThan(l,max_r)) return -1;
	return ans;
}

int main() {
	int n, l, w;
	while(scanf("%d %d %d",&n,&l,&w) != EOF) {
		trace(printf("%d %d %d\n\n",n,l,w););
		vector<POINT> arr;
		for(int i = 0; i < n; i++) {
			int x, r;
			scanf("%d %d",&x,&r);
			if(x < 0 || x > l || greaterThan(w,r*2.0)) continue;
			POINT t(x,w,r);
			arr.push_back(t);
		}
		sort(arr.begin(),arr.end(),comp);
		trace(for(int i = 0; i < arr.size(); i++) printf("%f %f\n",arr[i].left,arr[i].right););
		printf("%d\n",solve(l,arr));
	}
}
