//Author:  Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1107
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_ALTURA = 10005;

int altura, comprimento;
vector<int> arr;

int solve() {
  int ans = 0;
  for(int i = arr.size() - 1; i > 0; i--) {

    if(arr[i] < arr[i - 1])
      continue;

    ans += abs(arr[i] - arr[i - 1]);
  }

  return ans;
}

int main() {
  while(scanf("%d %d",&altura,&comprimento) && altura+comprimento) {
    arr.clear();
    for(int i = 0; i < comprimento; i++) {
      int d; scanf("%d",&d);
      arr.push_back(d);
    }
    arr.push_back(altura);
    int ans = solve();
    printf("%d\n",ans);
  } 
}
