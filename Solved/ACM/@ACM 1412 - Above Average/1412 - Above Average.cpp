//Author:   Gilberto Alexandre dos Santos
//Website:  http://acm.tju.edu.cn/toj/showp1412.html

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main() {
    int C = 0;
    scanf("%d",&C);
    for(short i = 0; i < C; i++) {
        int N = 0;
        scanf("%d",&N);
        float average[N];
        float soma = 0;
        for(short j = 0; j < N; j++) {            
            scanf("%f",&average[j]);
            soma += average[j];
        }
        float media = soma / N;
        float contador = 0;
        for(short j = 0; j < N; j++) 
            (average[j] > media) ? contador++ : false;
        float x = (100 * contador) / N;
        printf("%.3f%%\n",x);
    }
    return 0;
}