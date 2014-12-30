//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1608

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_I = 1e4 + 10;

int ingreds[MAX_I];
int D, I, B;

int main() {
  int ts;
  scanf("%d", &ts);
  for (int t = 0; t < ts; t++) {
    scanf("%d %d %d", &D, &I, &B);
    for (int i = 0; i < I; i++)
      scanf("%d", &ingreds[i]);

    int min_bolo_price = -1;
    for (int b = 0; b < B; b++) {
      int qi;
      scanf("%d", &qi); // qi quqtidate tipos de ingredientes
      int bolo_price = 0;
      for (int i = 0; i < qi; i++) {
        int qtd, ing;
        scanf("%d %d", &ing, &qtd);
        bolo_price += ingreds[ing] * qtd;
      }

      if (min_bolo_price > -1)
        min_bolo_price = min(min_bolo_price, bolo_price);
      else
        min_bolo_price = bolo_price;
    }

    printf("%d\n", D / min_bolo_price);
  }
  return 0;
}
