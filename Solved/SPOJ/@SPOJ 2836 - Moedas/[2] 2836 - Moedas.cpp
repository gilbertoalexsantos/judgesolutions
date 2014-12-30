#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_MOEDA = 105;
const int MAX_PRECO = 50005;
const int INF = 1e9;

int preco, qt_moeda;
int moedas[MAX_MOEDA];
int qt_moedas[MAX_PRECO];

int bfs() {
  queue<int> qe; qe.push(0);
  qt_moedas[0] = 0;
  for(int i = 1; i <= preco; i++)
    qt_moedas[i] = INF;
  while(!qe.empty()) {
    int v = qe.front(); qe.pop();
    if(v == preco)
      return qt_moedas[v];
    for(int i = 0; i < qt_moeda; i++) {
      int nv = v + moedas[i];
      if(nv <= preco && qt_moedas[nv] > qt_moedas[v] + 1) {
        qt_moedas[nv] = qt_moedas[v] + 1, qe.push(nv);
      }
    }
  }
  return -1;
}

int main() {
  while(scanf("%d",&preco) && preco) {
    scanf("%d",&qt_moeda);

    for(int i = 0; i < qt_moeda; i++)
      scanf("%d",&moedas[i]);

    int ans = bfs();
    ans == -1 ? printf("Impossivel\n") : printf("%d\n",ans);
  } 
}
