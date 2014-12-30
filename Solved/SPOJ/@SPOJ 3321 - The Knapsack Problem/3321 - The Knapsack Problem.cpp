//Author:   Gilberto Alexandre dos Santos
//Website:  http://www.spoj.com/problems/KNAPSACK/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int S, N;
int matriz[2000 + 10][2000 + 10] = {0};
int size[2000 + 10], value[2000 + 10];

int mochila() {
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= S; j++) {
            matriz[i][j] = matriz[i - 1][j];
            if (j - size[i] >= 0)
                matriz[i][j] = max(matriz[i][j], matriz[i - 1][j - size[i]] + value[i]);
        }
    return matriz[N][S];
}

int main() {
    scanf("%d %d", &S, &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &size[i + 1], &value[i + 1]);
    printf("%d\n", mochila());
    return 0;
}
