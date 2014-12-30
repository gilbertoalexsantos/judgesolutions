//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1433

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

struct type {
  int q, y;

  type(int q=0, int y=0) : q(q), y(y) {}
  bool operator< (const type &other) const { return q < other.q; }
};

bool lessOrEqual(double a, double b) { return (a - b) < EPS; }

int k;
double r;
vector<type> ar;

int getGroup(int left) {
  if(ar.size() == 1) return 1;
  int right = left;
  double t = 1.0;
  do {
    right++;
    t = (double) ar[right].q / ar[left].q; 
  } while(right < ar.size() && lessOrEqual(t,r));
  return right;
}

int main() {
  while(scanf("%d %lf",&k,&r) && k) {
    ar.assign(k,type());
    for(int i = 0; i < k; i++) {
      int q, y; scanf("%d %d",&q,&y);
      ar[i] = type(q,y);
    }
    sort(ar.begin(),ar.end());
    int group = getGroup(0);
    int ans = 1;
    while(group < ar.size()) {
      ans++;
      group = getGroup(group);
    }
    printf("%d\n",ans);
  }
}
