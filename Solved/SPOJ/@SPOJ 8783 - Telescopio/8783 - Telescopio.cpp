//Author:   Gilberto Alexandre dos Santos
//Website:  http://br.spoj.pl/problems/TELESCO2/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main() {
    short A = 0;
    scanf("%hd",&A);
    short N = 0;
    scanf("%hd",&N);
    short resposta = 0;
    for(short i = 0; i < N; i++) {
        short F = 0;
        scanf("%hd",&F);
        ((A * F) >= 40000000) ? resposta++ : false;
    }
    printf("%hd",resposta);
    return 0;
}