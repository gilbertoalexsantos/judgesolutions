#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_MOEDA = 105;
const int MAX_PRECO = 50005;
const int INF = 1e9;

int memo[MAX_PRECO];

int preco, qt_moeda;
int moedas[MAX_MOEDA];

int main() {
  while(scanf("%d",&preco) && preco) {
    scanf("%d",&qt_moeda);

    for(int i = 0; i < qt_moeda; i++)
      scanf("%d",&moedas[i]);

    for(int i = 0; i <= preco; i++)
      memo[i] = INF;

    memo[0] = 0;

    for(int i = 0; i < qt_moeda; i++) {
      int w = moedas[i];
      for(int j = 0; j <= preco; j++) {
        if(j - w >= 0)
          memo[j] = min(memo[j],memo[j - w] + 1);
      }
    }

    int ans = memo[preco];
    ans == INF ? printf("Impossivel\n") : printf("%d\n",ans);
  } 
}

