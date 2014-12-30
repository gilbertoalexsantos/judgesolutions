//Author: Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=448

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int N, S;
int output[2];

void best_rota(int vetor[], int tamanho)
{
  int sm = 0; int temp = 0;
  int inicio = 1; int fim = 0;
  for(int i = 0; i < tamanho; i++)
  {
    temp += vetor[i];
    fim++;
    if( (temp >= sm) && (temp != 0) )
    {
      if( (temp == sm) && ((fim+1-inicio) <= (output[1] - output[0])) ) // Pegando maior rota das rotas com SOMA igual
      {} // Se a Soma Máxima for igual porém o tamanho for Menor/Igual, então não faça nada
      else
      {
        sm = temp;
        output[0] = inicio;
        output[1] = fim+1;
      }
    }
    else
    {
      if(temp < 0)
      {
        temp = 0;
        inicio = i+2;
      }
    }
  }    
} 

int main()
{
  scanf("%d",&N);
  for(int i = 0; i < N; i++)
  {
    scanf("%d",&S);
    int niceness[S-1];
    for(int j = 0; j < (S-1); j++)
    {scanf("%d",&niceness[j]);} 
    output[0] = 0; output[1] = 0;   
    best_rota(niceness,(S-1));
    if(output[0] != 0)
    {cout << "The nicest part of route " << (i+1) << " is between stops " << output[0] << " and " << output[1];}
    else
    {cout << "Route " << (i+1) << " has no nice parts";} 
    cout << "\n";      
  }                                             
  return 0;      
}
