//Author: Gilberto A. dos Santos
//Website: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=655&page=show_problem&problem=4966

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const long double EPS = 1e-13;

int n;
long double p, s, v;

inline bool lessThan(long double u, long double v) { return (u - v) < EPS; }
inline long double _log2(long double n) { return log(n) / log(2.0); }
inline long double computerTime(long double c) {
  return (n * pow(_log2(n), c * sqrt(2))) / (p * 1e9);
}
inline long double flyTime(long double c) { return (s * (1.0 + 1.0/c)) / v; }
inline long double totalTime(long double c) { return computerTime(c) + flyTime(c); }

long double getLimit() {
  long double minFound = totalTime(1e-6);
  long double limit = 10.0;
  long double limitTime = totalTime(limit);
  while (lessThan(limitTime, minFound)) {
    minFound = limitTime;
    
    limit *= 10.0;
    limitTime = totalTime(limit);
  }
  return limit;
}

int main() {
  while (scanf("%d %Lf %Lf %Lf", &n, &p, &s, &v) != EOF) {
    long double left = 1e-9;
    long double right = getLimit();
    while (fabs(left - right) > EPS) {
      long double tr = (right - left) / 3;
      long double lo = left + tr;
      long double hi = lo + tr;
      if (lessThan(totalTime(lo), totalTime(hi))) {
        right = hi;
      } else {
        left = lo;
      }
    }
    long double c = (right + left) / 2.0;
    long double ans = totalTime(c);
    printf("%.10Lf %.10Lf\n", ans, c);
  }
}
