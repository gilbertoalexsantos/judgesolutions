//Author: Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1579

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;

int q, t, f;
int panels[MAX];

bool can(int value, int qt, int pos=0) {
  if(qt == 0) {
    return value == 0;
  }

  if(value < 0)
    return false;

  for(int i = pos; i < q-qt+1; i++) {
    bool t = can(value-panels[i],qt-1,i+1); 
    if(t)
      return true;
  }

  return false;
}

int main() {
  int qt; scanf("%d",&qt);
  while(qt--) {
    scanf("%d %d %d",&q,&t,&f);
    for(int i = 0; i < q; i++)
      scanf("%d",&panels[i]);
    sort(panels,panels+q);
    for(int i = 0; i < q; i++)
      printf("%d ",panels[i]);
    puts("");
    int tleft = q/t + (q % t != 0);
    int left = 0, right = 0, mid;
    for(int i = 0; i < t && i < q; i++)
      left += panels[i];
    for(int i = q; i > 0 && i > (q-t-1); i--)
      right += panels[i];
    while(left+1 <= right) {
      mid = (left+right)/2;
      if(can(mid,tleft)) {
        right = mid;
      } else {
        left = mid+1;
      }
    }
    printf("%d\n",right);
  }
}
