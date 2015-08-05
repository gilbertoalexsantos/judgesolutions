//Author: Gilberto A. dos Santos
//Website: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=655&page=show_problem&problem=4967

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int TRIES = 1000;

struct point {
  int x, y;
  point() : x(0), y(0) {}
  point(int x, int y) : x(x), y(y) {}
} points[100005];

inline int getQtPoints(int qtPoints, int percentage) {
  return ceil((double) (percentage * qtPoints) / 100.0);
}

inline unsigned int randn() {
  static unsigned int rseed = 42;
  return rseed = 22695477 * rseed + 1;
}

/*
  m1 = (iy - p1y) / (ix - p1x)
  m2 = (iy - p2y) / (ix - p2x)

  m1 == m2

  (iy - p1y) * (ix - p2x) == (iy - p2y) * (ix - p1x)
 */
bool inside(point i, point p1, point p2) {
  return (long long) (i.y - p1.y) * (i.x - p2.x) ==
    (long long) (i.y - p2.y) * (i.x - p1.x);    
}

bool possible(int n, int p) {
  if (n == 1) {
    return true;
  }
  int neededPoints = getQtPoints(n, p);
  for (int i = 0; i < TRIES; i++) {
    int p1 = randn() % n;
    int p2;
    do {
      p2 = randn() % n;
    } while (p2 == p1);
    
    int qt = 0;
    for (int j = 0; j < n; j++)
      qt += inside(points[j], points[p1], points[p2]);
    
    if (qt >= neededPoints)
      return true;
  }
  return false;
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int p; scanf("%d", &p);
    for (int i = 0; i < n; i++)
      scanf("%d %d", &points[i].x, &points[i].y);
    bool ans = possible(n, p);
    printf("%s\n", ans ? "possible" : "impossible");
  }
}
