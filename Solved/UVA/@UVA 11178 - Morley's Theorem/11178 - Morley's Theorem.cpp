//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2119

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

double EPS = 1e-9;

struct point {
  double x, y;
  point(double x=0.0, double y=0.0) : x(x), y(y) {}
  point operator+ (const point &other) const {
    return point(x + other.x, y + other.y);
  }
  point operator- (const point &other) const {
    return point(x - other.x, y - other.y);
  }
  point operator* (const double p) const  {
    return point(x * p, y * p);
  }
}; typedef point vec;

double dot(vec a, vec b) { return a.x*b.x + a.y*b.y; }
double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }
double len(vec a) { return sqrt(dot(a,a)); }
double angle(vec a, vec b) { return acos((dot(a,b))/len(a)/len(b)); }
vec rotate(vec a, double rad) { return vec(a.x*cos(rad)-a.y*sin(rad), a.x*sin(rad)+a.y*cos(rad)); }
point intersection(point P, vec v, point Q, vec w) {
  vec u = P - Q;
  double t = cross(w,u)/cross(v,w);
  return P + v*t;
}

point getAns(point a, point b, point c) {
  vec BC = c-b, BA = a-b;
  double angle1 = angle(BC,BA);
  BC = rotate(BC, angle1/3.0);

  vec CA = a-c, CB = b-c;
  double angle2 = angle(CA,CB);
  CA = rotate(CA, angle2*2/3.0);

  return intersection(b, BC, c, CA);
}

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    point a, b, c;
    scanf("%lf %lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);

    point d = getAns(a,b,c);
    point e = getAns(b,c,a);
    point f = getAns(c,a,b);

    printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",d.x,d.y,e.x,e.y,f.x,f.y);
  }
}
