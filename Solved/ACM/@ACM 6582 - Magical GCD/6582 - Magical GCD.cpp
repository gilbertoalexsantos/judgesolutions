//Author: Gilberto A. dos Santos
//Website: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=610&page=show_problem&problem=4593

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define mp make_pair

const int INF = 1e9;

long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long calc(long long gcd_, int pos, int size) { return gcd_ * (size - pos + 1); }

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    int n; scanf("%d",&n);
    long long arr[n];
    for(int i = 0; i < n; i++)
      scanf("%lld",&arr[i]);

    long long ans = arr[0];
    vector<pair<long long, int> > vt; vt.push_back(mp(arr[0],0));
    for(int i = 1; i < n; i++) {
      vector<pair<long long, int> > flag_vt;
      for(int j = 0; j < vt.size(); j++) {
        long long gcd_ = vt[j].first;
        long long new_gcd = gcd(gcd_, arr[i]);
        vt[j].first = new_gcd;
      }
      vt.push_back(mp(arr[i],i));
      sort(vt.begin(),vt.end());
      for(int j = 0; j < vt.size(); j++) {
        if(!j || vt[j-1].first != vt[j].first)
          flag_vt.push_back(vt[j]);
      }
      swap(flag_vt,vt);
      for(int j = 0; j < vt.size(); j++) {
        long long gcd_ = vt[j].first;
        int left_most = vt[j].second;
        ans = max(ans,calc(gcd_,left_most,i));
      }
    }
    printf("%lld\n",ans);
  }
}
