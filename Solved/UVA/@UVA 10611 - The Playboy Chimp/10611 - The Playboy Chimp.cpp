//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int>::iterator IT;

const int MAX_LADY = 50005;

int n;
vector<int> arr;

int main() {
  scanf("%d",&n);
  arr.assign(n,0);
  for(int i = 0; i < n; i++)
    scanf("%d",&arr[i]);
  int Q; scanf("%d",&Q);
  while(Q--) {
    int x;
    scanf("%d",&x);
    IT a = lower_bound(arr.begin(),arr.end(),x);
    IT b = upper_bound(arr.begin(),arr.end(),x);
    if(a != arr.end()) {
      int pos = a - arr.begin();
      if(pos != 0)
        printf("%d",arr[pos-1]);
      else
        printf("X");
    }
    else
      printf("%d",arr[n-1]);
    if(b != arr.end())
      printf(" %d",*b);
    else
      printf(" X");
    puts("");
  }
}
