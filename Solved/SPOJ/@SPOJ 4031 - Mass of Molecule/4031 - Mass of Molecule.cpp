//Author:   Gilberto Alexandre dos Santos
//Website:  http://www.spoj.com/problems/MMASS/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;

string x;
int i;

int getN(char x) {
    if (x == 'H') return 1;
    if (x == 'C') return 12;
    if (x == 'O') return 16;
    return 0;
}

int recursao(int &i) {
    if (i < 0) return 0;
    if (getN(x[i])) return getN(x[i]) + recursao(--i);
    if (x[i] == '(') return 0;
    if (x[i] == ')') {
        int g = 0; 
        i--;
        while (x[i] != '(')
            g += recursao(i);
        i--;
        return g;
    }
    if (isdigit(x[i])) {
        int z = x[i] - '0';
        if (getN(x[i - 1])) {
            i -= 2;
            return z * getN(x[i + 1]) + recursao(i);
        } else return z * recursao(--i);
    }
}

int main() {
    cin >> x;
    i = x.size() - 1;
    int soma = 0;
    while(i > -1) soma += recursao(i);
    cout << soma;
    return 0;
}