//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/SALDO/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    short N = 0, contador = 0;
    while (scanf("%hd", &N) && N != 0) {
        short x = 0, y = 0, max = 0, temp = 0, inicio = 1, fim = 0, respI = 0, respF = 0;
        for (short i = 0; i < N; i++) {
            scanf("%hd %hd", &x, &y);
            temp += x - y;
            fim++;
            if ((temp >= max) && (temp != 0)) {
                if ((temp == max) && ((fim - inicio) <= (respF - respI))) {
                } else {
                    max = temp;
                    respI = inicio;
                    respF = fim;
                }
            } else {
                if(temp < 0) {
                    temp = 0;
                    inicio = i + 2;
                }
            }
        }
        (max <= 0) ? (respI = -1) : false;
        if(respI != -1)
            printf("Teste %hd\n%hd %hd\n\n",++contador,respI,respF);
        else
            printf("Teste %hd\nnenhum\n\n",++contador);
    }
    return 0;
}