//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/CELETRIC/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int A, B;

int i1 = 100;
int i2 = 10000;
int i3 = 1000000;

int v1 = 2 * i1;
int v2 = v1 + 3 * (i2 - i1);
int v3 = v2 + 5 * (i3 - i2);

int calc_consumo(int valor) {
    if (valor > v3)
        return (1000000 + ((valor - v3) / 7));
    else if (valor > v2)
        return (10000 + ((valor - v2) / 5));
    else if (valor > v1)
        return (100 + ((valor - v1) / 3));
    else
        return (valor / 2);
}

int calc_preco(int valor) {
    if (valor > i3)
        return (v3 + 7 * (valor - 1000000));
    else if (valor > i2)
        return (v2 + 5 * (valor - 10000));
    else if (valor > i1)
        return (v1 + 3 * (valor - 100));
    else
        return (valor * 2);
}

int bb(int esq, int dir, int consumoTotal) {
    int meio = (esq + dir) / 2;
    int diferenca = abs(calc_preco(meio) - calc_preco(consumoTotal - meio));
    //printf("Esq - %d\nMeio - %d\nDir - %d\nDiferenca - %d\nB - %d\n", esq, meio, dir, diferenca, B);
    //printf("A - %d\nPreco Meio - %d\nPrecoT-M - %d\n\n", A, calc_preco(meio), calc_preco(consumoTotal - meio));
    if (diferenca < B)
        bb(esq, meio, consumoTotal);
    else if (diferenca > B)
        bb(meio, dir, consumoTotal);
    else
        return calc_preco(meio);
}

int main() {
    while (scanf("%d %d", &A, &B) && A != 0)
        printf("%d\n", bb(0, calc_consumo(A), calc_consumo(A)));
    return 0;
}
