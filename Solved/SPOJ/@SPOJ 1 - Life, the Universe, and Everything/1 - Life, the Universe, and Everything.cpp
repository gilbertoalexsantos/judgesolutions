//Author:   Gilberto A. dos Santos
//Website:  http://www.spoj.pl/problems/TEST/

#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int n;

int main() {
    while (scanf("%d", &n) && n != EOF)
        if(n != 42) printf("%d\n", n);
        else break;
}