#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_MOEDA = 105;
const int MAX_PRECO = 50005;
const int INF = 1e9;

int memo[MAX_MOEDA][MAX_PRECO];

int preco, qt_moeda;
int moedas[MAX_MOEDA];

int main() {
  while(scanf("%d",&preco) && preco) {
    scanf("%d",&qt_moeda);

    for(int i = 0; i < qt_moeda; i++)
      scanf("%d",&moedas[i]);

    for(int i = 0; i < qt_moeda; i++)
      for(int j = 0; j <= preco; j++)
        memo[i][j] = INF;

    for(int i = 0; i < qt_moeda; i++)
      memo[i][0] = 0;

    for(int i = 0; i <= preco; i++)
      if(i - moedas[0] >= 0)
        memo[0][i] = memo[0][i-moedas[0]] + 1;

    for(int pos_moeda = 1; pos_moeda < qt_moeda; pos_moeda++) {
      int w = moedas[pos_moeda];
      for(int bag = 1; bag <= preco; bag++) {
        int &ret = memo[pos_moeda][bag];
        if(bag - w >= 0)
          ret = min(ret,memo[pos_moeda-1][bag - w] + 1); 
        ret = min(ret,memo[pos_moeda-1][bag]);
        if(bag - w >= 0)
          ret = min(ret,memo[pos_moeda][bag - w] + 1);
      }
    }

    int ans = memo[qt_moeda-1][preco];
    ans == INF ? printf("Impossivel\n") : printf("%d\n",ans);
  } 
}
