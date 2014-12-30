#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

typedef unsigned long long ll;

int qt_digits(ll n) {
  stringstream s;
  string t;
  s << n;
  s >> t;
  return t.size();
}

inline void pr_white(int n) { for(int i = 0; i < n; i++) printf(" "); }

int main() {
  int cases = 4;
  int qt; scanf("%d",&qt);
  while(qt--) {
    int n; scanf("%d",&n);
    ll m[n][n];
    int pad[n];
    memset(pad,-1,sizeof pad);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) {
        ll x; scanf("%llu",&x);
        m[i][j] = x*x;
        pad[j] = max(pad[j],qt_digits(m[i][j]));
      }
    printf("Quadrado da matriz #%d:\n",cases++);
    for(int i = 0; i < n; i++) {
      int q_temp = pad[0] - qt_digits(m[i][0]);
      pr_white(q_temp);
      printf("%llu",m[i][0]);
      for(int j = 1; j < n; j++) {
        q_temp = pad[j] - qt_digits(m[i][j]);
        pr_white(q_temp);
        printf(" %llu",m[i][j]);
      }
      puts("");
    }
    if(qt) puts("");
  }
}
