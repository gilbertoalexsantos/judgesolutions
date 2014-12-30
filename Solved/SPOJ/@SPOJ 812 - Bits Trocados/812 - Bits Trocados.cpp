//Author: Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/BIT/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    short V = 0, contador = 0;
    while(scanf("%hd",&V) && V != 0) {
        short I = 0, J = 0, K = 0, L = 0;
        I = V / 50;
        V = V - (I * 50);
        J = V / 10;
        V = V - (J * 10);
        K = V / 5;
        V = V - (K * 5);
        L = V / 1;
        V = V - (L * 1);
        printf("Teste %hd\n%hd %hd %hd %hd\n\n",++contador,I,J,K,L);
    }       
    return 0;
}
