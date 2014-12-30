//Author: Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/en/problems/view/1288

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 60;
const int INF = 1e9;

const char word[2][50] = {
  "Falha na missao\0",
  "Missao completada com sucesso\0"
};

int n, size, resistance, sum;
int damage[MAX], weight[MAX];

bool solve() {
  int memo[size+1];
  memset(memo,0,sizeof memo);
  for(int i = 0; i < n; i++) {
    int d = damage[i], w = weight[i];
    for(int j = size; j >= w; j--) {
      if(j-w == 0 || memo[j-w]) {
        memo[j] = max(memo[j],memo[j-w]+d);
        if(memo[j] >= resistance)
          return true;
      }
    }
  }
  return false;
}

int main() {
  int T; scanf("%d",&T);
  while(T--) {
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
      scanf("%d %d",&damage[i],&weight[i]);
    scanf("%d %d",&size,&resistance);
    bool ans = solve();
    printf("%s\n",word[ans]);
  }
}
