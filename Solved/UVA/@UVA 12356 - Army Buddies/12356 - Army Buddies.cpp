//Author:   Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3778

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

int numero_soldados, numero_reports, esq, dir;

struct dado {
    int prox;
    int ant;
};

int main() {
    while (scanf("%d %d", &numero_soldados, &numero_reports) && numero_soldados != 0) {
        dado pelotao[numero_soldados + 1];
        if (numero_soldados == 1) {
            pelotao[1].ant = -1;
            pelotao[1].prox = -1;
        } else {
            for (int i = 1; i <= numero_soldados; i++) {
                if (i == 1) {
                    pelotao[i].ant = -1;
                    pelotao[i].prox = 2;
                }
                if (i == numero_soldados) {
                    pelotao[i].ant = i - 1;
                    pelotao[i].prox = -1;
                }
                if ((i != 1) && (i != numero_soldados)) {
                    pelotao[i].ant = i - 1;
                    pelotao[i].prox = i + 1;
                }
            }
        }
        for (int i = 0; i < numero_reports; i++) {
            scanf("%d %d", &esq, &dir);
            pelotao[pelotao[esq].ant].prox = pelotao[dir].prox;
            pelotao[pelotao[dir].prox].ant = pelotao[esq].ant;
            if (pelotao[esq].ant == -1) printf("* ");
            else printf("%d ", pelotao[esq].ant);
            if (pelotao[dir].prox == -1) printf("*");
            else printf("%d", pelotao[dir].prox);
            printf("\n");
        }
        printf("-\n");
    }
    return 0;
}