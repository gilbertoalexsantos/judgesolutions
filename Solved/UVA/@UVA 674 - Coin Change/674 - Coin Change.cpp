//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=615

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int coin[] = {1, 5, 10, 25, 50};
const int size = 5;
const int MAX = 7500;

int n;
int memo[MAX+1];

void dp() {
  memset(memo,0,sizeof memo); 
  memo[0] = 1;
  for(int i = 0; i < size; i++) {
    int c = coin[i];
    for(int j = c; j <= MAX; j++)
      memo[j] += memo[j - c];
  }
}

int main() {
  dp();
  while(scanf("%d",&n) != EOF) {
    printf("%d\n",memo[n]);
  }
}
