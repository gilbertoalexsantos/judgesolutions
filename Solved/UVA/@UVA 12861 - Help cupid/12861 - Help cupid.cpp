//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4726

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1e9;

inline int calc(int n1, int n2) { return min(abs(n1-n2),24-abs(n1-n2)); }

int main() {
  int n;
  while(scanf("%d",&n) != EOF) {
    int arr[n];
    for(int i = 0; i < n; i++)
      scanf("%d",&arr[i]);
    
    sort(arr,arr+n);
    
    int a[n*2];
    for(int i = 0; i < n; i++)
      a[i] = arr[i];
    for(int i = n; i < n*2; i++)
      a[i] = arr[i-n];

    int sum = INF;
    for(int i = 0; i < n; i++) {
      int flag = 0;
      for(int j = i; j < i+n-1; j += 2)
        flag += calc(a[j],a[j+1]);
      sum = min(sum,flag);
    }
    
    printf("%d\n",sum);
  }
}
