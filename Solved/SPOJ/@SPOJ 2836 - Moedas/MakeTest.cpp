#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_PRECO = 50000;
const int MAX_MOEDA = 100;

const int VALUE_MOEDA = 50000;

int main() {
  srand(time(NULL));
  int a = abs(rand() % MAX_PRECO);
  while(!a)
    a = abs(rand() % MAX_PRECO);
  int b = abs(rand() % MAX_MOEDA);
  while(!b)
    b = abs(rand() % MAX_MOEDA);
  printf("%d %d\n",a,b);

  bool has[MAX_PRECO];
  vector<int> moedas;
  for(int i = 0; i < b; i++) {
    int c = abs(rand() % VALUE_MOEDA);
    while(!c && has[c])
      c = abs(rand() % VALUE_MOEDA);
    if(c == 0)
      c = 1;
    has[c] = true;
    moedas.push_back(c) ;
  }
  sort(moedas.begin(),moedas.end());
  for(int i = 0; i < moedas.size(); i++)
    printf("%d\n",moedas[i]);
  printf("0\n");
}
