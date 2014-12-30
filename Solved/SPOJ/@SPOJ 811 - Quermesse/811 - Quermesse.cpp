//Author: Gilberto Alexandre dos Santos
//Website:  http://br.spoj.com/problems/QUERM/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    short n = 0, contador = 0;
    while(scanf("%hd",&n) && n != 0) {
        short m = 0, retorno = 0;
        for(short i = 0; i < n; i++) {
            scanf("%hd",&m);
            (m == i+1) ? retorno = m : false;
        }
        printf("Teste %hd\n%hd\n\n",++contador,retorno);
    }        
    return 0;
}
