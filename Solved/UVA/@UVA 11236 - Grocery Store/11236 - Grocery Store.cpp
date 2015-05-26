//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2177

#include <cstdio>
#include <cstdlib>
#include <cmath>

typedef long long ll;

const ll LIMIT = 2000;
const ll OFFSET = 1e6;
const double EPS = 1e-9;

int main () {
  for (ll a = 1; a*4 <= LIMIT; a++) {
    for (ll b = a; a+b*3 <= LIMIT; b++) {
      for (ll c = b; a+b+c*2 <= LIMIT; c++) {
        ll mult = a*b*c, sum = a+b+c;

        if (mult <= OFFSET) {
          continue;
        }
        
        ll d = (sum * OFFSET) / (mult - OFFSET);

        if (d < c || sum+d > LIMIT) {
          continue;
        }

        double s = (a+b+c+d) / 100.0;
        double m = (a*b*c*d) / 100000000.0;

        if (fabs(s - m) < EPS) {
          printf("%.2lf %.2lf %.2lf %.2lf\n", a/100.0, b/100.0, c/100.0, d/100.0);
        }
      }
    }
  }
}
