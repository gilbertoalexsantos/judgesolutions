//Author: Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1133

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void solve(int left, int right) {
  for(int i = min(left,right)+1; i < max(left,right); i++) {
    int n = i % 5;
    if(n == 2 || n == 3)
      printf("%d\n",i);
  }
}

int main() {
  int x, y; scanf("%d %d",&x,&y);
  solve(x,y);
}
