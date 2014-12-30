//Author: Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1160

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int pa, pb;
double g1, g2;

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    scanf("%d %d %lf %lf",&pa,&pb,&g1,&g2);
    int i;
    for(i = 0; i < 100 && pa <= pb; i++) {
      pa += floor(((double) pa * g1) / 100.0);
      pb += floor(((double) pb * g2) / 100.0);
    }
    if(pa <= pb)
      i = -1;
    i == -1 ? printf("Mais de 1 seculo.\n") : printf("%d anos.\n",i);
  }
}
