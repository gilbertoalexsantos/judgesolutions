//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1590

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;

typedef long long ll;

int n, k;

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    scanf("%d %d",&n,&k);
    vector<int> arr;
    for(int i = 0; i < n; i++) {
      int x; scanf("%d",&x);
      arr.push_back(x);
    }

    bool visited[n];
    memset(visited,false,sizeof visited);
    int ans = 0;
    for(int i = 31; i >= 0; i--) {
      int qt_bit = 0;
      vector<int> used;
      for(int j = 0; j < arr.size(); j++) {
        if((1 << i & arr[j]))
          used.push_back(arr[j]);
      }
      if(used.size() >= k) {
        ans |= 1 << i;
        arr = used;
      }
    }

    printf("%d\n",ans);
  }
}
