//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=578

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int n;

int main() {
  while(scanf("%d",&n) && n) {
    printf("Printing order for %d pages:\n",n);

    if(n == 1) {
      printf("Sheet 1, front: Blank, 1\n");
      continue;
    }

    int left = 1, right = n + (n % 4 != 0 ? (4 - (n % 4)) : 0);
    for(int i = 1; i <= right / 2; i++) {
      printf("Sheet %d, front: ",i);
      right > n ? printf("Blank") : printf("%d",right);
      right--;
      printf(", ");
      printf("%d",left++);
      printf("\n");
      printf("Sheet %d, back : ",i);
      printf("%d",left++);
      printf(", ");
      right > n ? printf("Blank") : printf("%d",right);
      right--;
      printf("\n");
    }
  }
}
