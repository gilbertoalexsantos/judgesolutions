//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3812

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int N, B;
int P[500000];
int maior;

int buscaBinaria(int vetor[], int esq, int dir, int tamanho, int urnas, int best) { 
  while(esq + 1 < dir) {
    int temp = 0; 
    bool sair = true;
    int meio = (esq + dir) / 2; 

    temp += best/meio + (best % meio != 0);

    if(best * tamanho <= urnas)
      sair = false;

    if(sair == true) {
      sair = false; temp = 0;
      for(int i = 0; i < tamanho; i++) {                 
        if(vetor[i] % meio != 0)
          temp += vetor[i]/meio + 1;
        else
          temp += vetor[i]/meio;
        if(temp > urnas) {
          sair = true; 
          break;
        }
      }
    }

    if(sair == true)
      esq = meio;
    else
      dir = meio;
  }   
  return dir;   
} 

int main() {
  while(scanf("%d",&N) && N != -1) {
    maior = 0; 
    scanf("%d",&B);
    for(int i = 0; i < N; i++) {
      scanf("%d",&P[i]);
      maior = max(maior,P[i]);
    }
    printf("%d\n",buscaBinaria(P,0,5000000,N,B,maior));
  }
  return 0;
}
