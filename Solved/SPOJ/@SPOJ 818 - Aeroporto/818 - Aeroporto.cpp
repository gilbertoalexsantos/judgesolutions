//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.pl/problems/AERO/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    short A = 0, V = 0, contador = 0;
    while(scanf("%hd %hd",&A,&V) && A != 0) {
        short X = 0, Y = 0, vetor[A+1];
        for(short i = 0; i < A+1; i++) vetor[i] = 0;
        for(short i = 0; i < V; i++) {
            scanf("%hd %hd",&X,&Y);
            vetor[X]++; vetor[Y]++;
        }
        short maior = vetor[0];
        for(short i = 1; i < A+1; i++)
            (maior < vetor[i]) ? maior = vetor[i] : false;
        short resposta[A+1], tamanho = 0;
        for(short i = 0; i < A+1; i++) resposta[i] = 0;
        for(short i = 1; i < A+1; i++)
            (vetor[i] == maior) ? (resposta[tamanho++] = i) : false;
        printf("Teste %hd\n",++contador);
        for(short i = 0; i < tamanho; i++) {
            (i+1 != tamanho) ? printf("%hd ",resposta[i]) : printf("%hd",resposta[i]);    
        }
        printf("\n\n");     
    }    
    return 0;
}