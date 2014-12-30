//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1595

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;


int main() {
  int T; scanf("%d",&T);
  while(T--) {
    int s, c, r; scanf("%d %d %d",&s,&c,&r);
    int arr[s];
    for(int i = 0; i < s; i++)
      scanf("%d",&arr[i]);
    sort(arr,arr+s);
    double ans = 0.0;
    int i = 0;
    while(i < c && i < s) {
      int speed = arr[i++] + r;
      ans += (double) 1 / speed;
    }
    while(i < s)
      ans += (double) 1 / arr[i++];
    printf("%.2lf\n",ans);
  }
}
