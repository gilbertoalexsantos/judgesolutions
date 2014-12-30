//Author:   Gilberto Alexandre dos Santos
//Website:  http://migre.me/cbwFs

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <cstring>
#include<string>
using namespace std;

char number(char x) {
    char z[12] = "0123456789?";
    for (short i = 0; i < 10; i++) {
        if (x == z[i])
            return z[i];
    }
    return 'a';
}

int main() {
    string exp;
    int resposta = 0;
    while (cin >> exp) {
        char *palavra;
        palavra = new char[exp.size() + 1];
        strcpy(palavra, exp.c_str());
        char a[5], b[5], c[5];
        for(int i = 0; i < 4; i++) {
            a[i] = 'c'; b[i] = 'c'; c[i] = 'c';
        }
        short an = 0, bn = 0, cn = 0;

        // Pegando 1° Número
        short contador = 0, x = 0;
        while (number(palavra[contador]) != 'a') {
            a[x++] = number(palavra[contador]);
            contador++;
        }
        an = atoi(a);

        //Pegando 1° Operador
        char operador = palavra[contador];
        contador++;

        //Pegando 2° Número
        x = 0;
        while (number(palavra[contador]) != 'a') {
            b[x++] = number(palavra[contador]);
            contador++;
        }
        bn = atoi(b);

        //Retirando o igual
        contador++;

        //Pegando 3° Número
        x = 0;
        while ((number(palavra[contador]) != 'a') && contador < exp.size()) {
            c[x++] = number(palavra[contador]);
            contador++;
        }
        cn = atoi(c);

        if (c[0] != 'c') {
            if (operador == '+') {
                if ((an + bn) == cn)
                    resposta++;
            } else {
                if ((an - bn) == cn)
                    resposta++;
            }
        }
    }
    printf("%d\n",resposta);
    return 0;
}