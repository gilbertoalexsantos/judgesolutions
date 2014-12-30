//Author:   Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2113

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main() {
    short t = 0;
    scanf("%hd", &t);
    for (short i = 0; i < t; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        if (a == b)
            printf("=\n");
        else if (a < b)
            printf("<\n");
        else
            printf(">\n");
    }
    return 0;
}