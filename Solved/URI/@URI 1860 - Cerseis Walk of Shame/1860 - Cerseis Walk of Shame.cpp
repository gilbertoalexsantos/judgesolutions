//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1860

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<double, double> dd;

const int MAX_POINTS = 5 * 1e4 + 10;
const double EPS = 1e-9;

int n;
double x;
vector<dd> points(MAX_POINTS);

inline double distSquared(dd &a, dd &b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

double maxDist(double xx) {
  dd pxx(xx, 0.0);
  double maxDist = -1e9;
  for (int i = 0; i < n; i++) {
    double d = distSquared(pxx, points[i]);
    if (d > maxDist)
      maxDist = d;
  }
  return maxDist;
}

double fn(double xx) {
  return maxDist(xx);
}

int main() {
  scanf("%d %lf", &n, &x);
  for (int i = 0; i < n; i++) {
    dd p; scanf("%lf %lf", &p.first, &p.second);
    points[i] = p;
  }

  double lo = 0.0, hi = x;
  while (fabs(lo - hi) > EPS) {
    double lot = lo + (hi - lo) / 3.0, hit = hi - (hi - lo) / 3.0;
    if (fn(lot) < fn(hit))
      hi = hit;
    else
      lo = lot;
  }

  double xans = (hi + lo) / 2.0;
  double distxans = sqrt(maxDist(xans));
  printf("%.2lf %.2lf\n", xans, distxans);
}
