//Author:   Gilberto Alexandre dos Santos
//Website:  http://www.spoj.com/problems/EDIST/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;

int numero_testes;
string s1, s2;
int matriz[2000 + 1][2000 + 1];

int main() {
    scanf("%d", &numero_testes);
    while (numero_testes--) {
        cin >> s1;
        cin >> s2;
        for (int i = 0; i < s1.size(); i++)
            for (int j = 0; j < s2.size(); j++)
                matriz[i][j] = 0;
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                matriz[0][0] = 0;
                matriz[i][0] = i;
                matriz[0][j] = j;
                char s = s1[i - 1];
                char t = s2[j - 1];
                int substituicao = matriz[i - 1][j - 1] + !(s == t);
                int insercao = matriz[i][j - 1] + 1;
                int remocao = matriz[i - 1][j] + 1;
                matriz[i][j] = min(remocao, min(substituicao, insercao));
            }
        }
        printf("%d\n", matriz[s1.size()][s2.size()]);
    }
    return 0;
}