//Author: Gilberto A. dos Santos
//Website: http://codeforces.com/contest/490/problem/A

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;


int main() {
  vector<int> arr[4];
  int n; scanf("%d",&n);
  for(int i = 0; i < n; i++) {
    int x; scanf("%d",&x);
    arr[x].push_back(i);
  }
  int teams = min(arr[1].size(),min(arr[2].size(),arr[3].size()));
  int left = 0;
  printf("%d\n",teams);
  for(int i = 0; i < teams; i++) {
    printf("%d %d %d\n",arr[1][left]+1,arr[2][left]+1,arr[3][left]+1);
    left++;
  }
  
}
