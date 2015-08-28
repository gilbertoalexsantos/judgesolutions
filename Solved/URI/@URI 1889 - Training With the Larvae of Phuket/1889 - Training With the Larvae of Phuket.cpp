//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1889

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int MAX_N = 2 * 1e3;
const double EPS = 1e-13;

int n;
vector<double> triangles;

inline bool lessThan(const double s1, const double s2) { return (s1 - s2) < EPS; }

double heron(double s1, double s2, double s3) {
  double p = (s1 + s2 + s3) / 2.0;
  return sqrt(p * (p - s1) * (p - s2) * (p - s3));
}

double ternary_search(int lo, int hi, double s1, double s2) {
  while (lo <= hi) {
    int tr = (hi - lo) / 3;
    int l = lo + tr;
    int h = hi - tr;
    double s3l = triangles[l], s3h = triangles[h];
    double al = heron(s1, s2, s3l);
    double ah = heron(s1, s2, s3h);
    if (al < ah) {
      hi = h-1;
    } else {
      lo = l+1;
    }
  }
  double a = heron(s1, s2, triangles[hi]);
  return heron(s1, s2, triangles[hi]);
}

// s2 > s1
inline pair<double, double> getLimitSideTriangle(double s1, double s2) {
  return make_pair(s2-s1+EPS, s1+s2-EPS);
}

int main() {
  int t; scanf("%d\n", &t);
  while (t--) {
    scanf("%d", &n);
    triangles = vector<double>(n);
    
    for (int i = 0; i < n; i++)
      scanf("%lf", &triangles[i]);
    
    sort(triangles.begin(), triangles.end());

    double maxArea = 1e9;
    bool found = false;
    for (int i = 0; i+2 < n; i++) {
      double s1 = triangles[i];
      for (int j = i+1; j+1 < n; j++) {
        double s2 = triangles[j];
        pair<double, double> mins = getLimitSideTriangle(s1, s2);
        vector<double>::iterator it_low = lower_bound(triangles.begin()+j+1,
                                                      triangles.end(),
                                                      mins.first,
                                                      lessThan);
        vector<double>::iterator it_high = upper_bound(triangles.begin()+j+1,
                                                       triangles.end(),
                                                       mins.second,
                                                       lessThan);
        if (it_low != triangles.end() && it_low != it_high) {
          int low = it_low - triangles.begin();
          int high = (--it_high) - triangles.begin();
          if (!lessThan(triangles[high], mins.second))
            continue;
           found = true;
          double a = ternary_search(low, high, s1, s2);
          maxArea = min(maxArea, a);
        }
      }
    }

    if (!found) {
      puts("-1");
    } else {
      printf("%.2lf\n", maxArea);
    }
  }
}
