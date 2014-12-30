//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3634

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<double,double> dd;

const double EPS = 1e-9;

inline bool equalThan(double a, double b) { return fabs(a - b) < EPS; }
inline bool lessThan(double a, double b) { return (a - b) < EPS; }
inline bool lessOrEqual(double a) { return a < EPS; }

struct point {
  double x, y;
  point(double x, double y) : x(x), y(y) {}
  bool operator<(const point &other) const {
    if(equalThan(x,other.x))
      return lessThan(y,other.y);
    return lessThan(x,other.x);
  }
};

int n, d;
vector<point> seas;
bool check(point a, point b) {
  return lessOrEqual((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) - d*d);
}

int solve() {
  sort(seas.begin(),seas.end());
  printf("%d %.3lf\n",check(point(0,0),point(-2,4)),hypot(d,4));
  vector<dd> intervals;
  for(int i = 0; i < seas.size(); i++) {
    double distance = hypot(d,seas[i].y);
    intervals.push_back(dd(seas[i].x-distance,seas[i].x+distance));
  }
  int ans = 0;
  double flag = -1e9;
  int i = 0;
  for(int i = 0; i < intervals.size(); i++)
    printf("%.3lf %.3lf\n",intervals[i].first,intervals[i].second);
  while(i < n) {
    while(i < n && lessOrEqual(intervals[i].first - flag)) {
      if(lessThan(flag,intervals[i].second))
        flag = intervals[i].second;
      i++;
    }
    flag = intervals[i].second;
    ans++;
  }
  return ans;
}

int main() {
  int cases = 1;
  while(scanf("%d %d",&n,&d) && n+d) {
    seas.clear();
    for(int i = 0; i < n; i++) {
      int x, y; scanf("%d %d",&x,&y);
      seas.push_back(point(x,y));
    }
    int ans = solve();
    printf("Case %d: %d\n",cases++, ans);
  }
}
