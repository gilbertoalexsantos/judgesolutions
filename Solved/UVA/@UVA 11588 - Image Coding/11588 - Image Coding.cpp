//Author:   Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2635

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

struct dado {
    char letra;
    int quantidade;
};

int numero_testes, linhas, colunas, maxByte, minByte;
int vetor_letras[91];
int casos = 1;

int main() {
    scanf("%d", &numero_testes);
    while (numero_testes--) {
        for (int i = 65; i <= 90; i++) vetor_letras[i] = 0;
        scanf("%d %d %d %d", &linhas, &colunas, &maxByte, &minByte);
        char matriz[linhas][colunas];
        for (int i = 0; i < linhas; i++)
            scanf("%s", matriz[i]);
        for (int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++) {
                int numero_ascii = matriz[i][j];
                vetor_letras[numero_ascii]++;
            }
        int maior = 0, quant = 0, resp = 0;
        for (int i = 65; i <= 90; i++)
            if (maior < vetor_letras[i]) maior = vetor_letras[i];
        for (int i = 65; i <= 90; i++)
            if (maior == vetor_letras[i]) quant++;
        resp = (quant * maior * maxByte) + (((linhas * colunas) - (quant * maior)) * minByte);
        printf("Case %d: %d\n", casos++, resp);
    }
    return 0;
}