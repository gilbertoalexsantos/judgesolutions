//Author: Gilberto A. dos Santos
//Website:

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
  int n; scanf("%d",&n);

  int sum[10001]; sum[0] = 0;
  for(int i = 1; i <= 10000; i++)
    sum[i] = sum[i-1] + i;

  int level = 1, ans = 0;
  while(level <= 10000) {
    if(sum[level] <= n) {
      ans++;
      n -= sum[level++];
    } else {
      break;
    }
  }
  
  printf("%d\n",ans);
}
