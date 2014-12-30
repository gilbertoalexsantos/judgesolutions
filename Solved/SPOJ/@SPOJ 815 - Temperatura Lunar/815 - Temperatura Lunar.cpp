//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/LUA/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    short N = 0, M = 0, contador = 0;
    while (scanf("%hd %hd", &N, &M) && !(N == 0 && M == 0)) {
        short dados[N];
        for(short i = 0; i < N; i++)
            scanf("%hd",&dados[i]);
        short numerador = 0, menor = 10001, maior = -10001;
        for(short i = 0; i < M; i++)
            numerador += dados[i];
        short media = numerador / M;
        short begin = 0, end = M - 1;
        (menor > media) ? menor = media : false;
        (maior < media) ? maior = media : false;
        numerador -= dados[begin];
        begin++; end++;
        while(end < N) {
            numerador += dados[end];
            media = numerador / M;
            (menor > media) ? menor = media : false;
            (maior < media) ? maior = media : false;
            numerador -= dados[begin];
            begin++; end++;
        }
        printf("Teste %hd\n%hd %hd\n\n",++contador,menor,maior);
    }
    return 0;
}