#include <stdio.h>

#include <set>

using namespace std;

set<int> mark;

int n, m, inv[3010][2], ni;

int getval(int a) {
  for (int i = ni-1; i >= 0; i--) {
    if (a <= inv[i][1] && a >= inv[i][0]) {
      a = inv[i][0] + inv[i][1] - a;
    }
  }
  return a;
}

long long sumr(int a, int b) {
  long long ma = min(a,b);
  long long mb = max(a,b);
  return (ma+mb)*(mb-ma+1LL)/2LL;
}

long long sum(int a, int b) {
  int va, vb, pb, pa;
  pa = a;
  long long su = 0;
  while (pa <= b) {
    va = getval(pa);
    typeof(mark.begin()) it = mark.lower_bound(pa);
    if (it == mark.end())
      pb = b;
    else
      pb = min(*(mark.lower_bound(pa)), b);
    vb = getval(pb);
    su += sumr(va, vb);
    //printf ("pa %d pb %d su %ld\n", pa, pb, su);
    pa = pb+1;
  }
  return su;
}

int main () {

  int a, b;
  char t;
  ni = 0;
  scanf ("%d %d ", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf (" %c %d %d", &t, &a, &b);
        
    if (t == 'I') {
      inv[ni][0] = a;
      inv[ni][1] = b;
      mark.insert(a-1);
      mark.insert(b);
      ni++;
         
    }
    else
      printf("%lld\n", sum(a, b));
  }
  
  return 0;
}
