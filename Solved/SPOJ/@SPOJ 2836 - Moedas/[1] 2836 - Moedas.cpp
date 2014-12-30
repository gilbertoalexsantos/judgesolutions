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

int dp(int pos, int sum=0) {
  if(sum > preco | pos >= qt_moeda)
    return INF;

  if(sum == preco)
    return 1;

  int &ret = memo[pos][sum];
  if(ret != -1)
    return ret;

  // Pegar moeda e continuar nela
  int p1 = 1 + dp(pos,sum + moedas[pos]);

  // Nao pegar moeda
  int p2 = dp(pos + 1,sum);

  return ret = min(p1,p2);
}

int main() {
  while(scanf("%d",&preco) && preco) {
    scanf("%d",&qt_moeda);

    for(int i = 0; i < qt_moeda; i++)
      scanf("%d",&moedas[i]);

    memset(memo,-1,sizeof memo);

    int ans = dp(0);
    ans == INF ? printf("Impossivel\n") : printf("%d\n",ans);
  } 
}
