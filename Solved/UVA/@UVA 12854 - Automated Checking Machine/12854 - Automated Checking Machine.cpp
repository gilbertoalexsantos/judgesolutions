//Author: Gilberto A. dos Santos
//Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=861&page=show_problem&problem=4719

#include <cstdio>
#include <cstdlib>
using namespace std;

bool solve(int a1[], int a2[]) {
  for(int i = 0; i < 5; i++)
    if(a1[i] == a2[i])
      return false;
  return true;
}

int main() {
  int a, b;
  while(scanf("%d %d",&a,&b) != EOF) {
    int a1[5], a2[5]; a1[0] = a, a1[1] = b;
    for(int i = 2; i < 5; i++)
      scanf("%d",&a1[i]);
    for(int i = 0; i < 5; i++)
      scanf("%d",&a2[i]);
    printf("%s\n",solve(a1,a2) ? "Y" : "N");
  }
}
