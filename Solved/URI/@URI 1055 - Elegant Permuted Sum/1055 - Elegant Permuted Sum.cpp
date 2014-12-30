//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1055

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

inline int get(int a, int b) {  return abs(v[a]-v[b]);  }

int solve() {
  if(v.size() <= 2)
    return v.size() == 1 ? v[0] : get(0,1);

  sort(v.begin(),v.end());

  int ret = 0;
  // Número par de elementos
  // Uma alternativa:
  // 2 Maiores e 2 Menores
  if(v.size() % 2 == 0) {
    int mid = v.size() / 2;
    ret += v[mid]; ret -=v[mid-1];
    int left = 0, right = mid+1;
    while(left < mid-1)
      ret -= 2*v[left++];
    while(right < v.size())
      ret += 2*v[right++];
  }
  // Número ímpar de elementos
  // Duas alternativas:
  // 1º - Maiores > Menores
  // 2º - Maiores < Menores
  else {
    int q1 = 0, q2 = 0;
    int mid = v.size() / 2;
    
    // 1º
    q1 += v[mid]; q1 += v[mid+1];
    int left1 = 0, right1 = mid+2;
    while(left1 < mid)
      q1 -= 2*v[left1++];
    while(right1 < v.size())
      q1 += 2*v[right1++];

    // 2º
    q2 -= v[mid]; q2 -= v[mid-1];
    int left2 = 0, right2 = mid+1;
    while(left2 < mid-1)
      q2 -= 2*v[left2++];
    while(right2 < v.size())
      q2 += 2*v[right2++];

    ret = max(q1,q2);
  }

  return ret;
}

int main() {
  int T, cases = 1;
  scanf("%d",&T);
  while(T--) {
    v.clear();
    int s; scanf("%d",&s);
    for(int i = 0; i < s; i++) {
      int x; scanf("%d",&x);
      v.push_back(x);
    }
    int ans = solve();
    printf("Case %d: %d\n",cases++,ans);
  }
}
