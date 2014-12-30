//Author: Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/METEORO/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    short X1 = 0, X2 = 0, Y1 = 0, Y2 = 0, contador = 0;
    while (scanf("%hd %hd %hd %hd", &X1, &Y1, &X2, &Y2) && !(X1 == 0 && Y1 == 0 && X2 == 0 && Y2 == 0)) {
        short N = 0, resposta = 0;
        scanf("%hd", &N);
        short X = 0, Y = 0;
        for (short i = 0; i < N; i++) {
            scanf("%hd %hd", &X, &Y);
            if ((X >= X1) && (X <= X2) && (Y <= Y1) && (Y >= Y2))
                resposta++;
        }
        printf("Teste %hd\n%hd\n\n", ++contador, resposta);
    }
    return 0;
}
