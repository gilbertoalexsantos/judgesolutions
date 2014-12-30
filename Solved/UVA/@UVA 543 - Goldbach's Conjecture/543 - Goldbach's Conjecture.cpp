//Author: Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=484

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<math.h>
#include<vector>
using namespace std;

bool primo[1000000 + 1];
int n;

int main() {
    int raiz = sqrt(1000000);
    for (int i = 0; i <= 1000000; i++) primo[i] = 1;
    vector<int> primos;
    for (int i = 2; i < raiz; i++) {
        int qua = pow(i, 2);
        if (qua > 1000000) break;
        if (primo[i]) for (int j = qua; j <= 1000000; (j += i)) primo[j] = 0;
    }
    primo[0] = 0;
    primo[1] = 0;
    for (int i = 2; i <= 1000000; i++) if (primo[i]) primos.push_back(i);
    while (scanf("%d", &n) && n != 0) {
        int pa = 0;
        int pb = 0;
        int entrou = false;
        for (int i = 0; i < primos.size(); i++) {
            pa = primos[i];
            if(pa > n/2) break;
            pb = n - pa;
            if (primo[pb]) {
                entrou = true;
                break;
            }
        }
        if (entrou) printf("%d = %d + %d\n", n, pa, pb);
        else printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
