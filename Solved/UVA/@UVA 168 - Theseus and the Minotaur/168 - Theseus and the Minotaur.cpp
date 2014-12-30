//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=104

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

string entrada;
char theseus, minotaur;
int k;

void dfs(int t, int m, vector<int> grafo[], bool marcado[], vector<int> &resposta) {
    int qt = k;
    while (1) {
        bool entrou = 0;
        if (!k) {
            k = qt;
            marcado[t] = 1;
            resposta.push_back(t);
        }
        for (int i = 0; i < grafo[m].size(); i++) {
            if (!marcado[grafo[m][i]] && grafo[m][i] != t) {
                entrou = 1;
                k--;
                t = m;
                m = grafo[m][i];
                break;
            }
        }
        if (!entrou) {
            resposta.push_back(m);
            break;
        }
    }
}

int main() {
    while (cin >> entrada && entrada[0] != '#') {
        cin >> minotaur >> theseus >> k;
        vector<int> resposta;
        vector<int> grafo[26];
        bool marcado[26];
        for (int i = 0; i < 26; i++) marcado[i] = 0;
        int t = theseus - 'A';
        int m = minotaur - 'A';
        for (int i = 0; i < entrada.size() - 1; i++) {
            int v = entrada[i] - 'A';
            i += 2;
            while (entrada[i] != ';' && i < entrada.size() - 1) {
                int n = entrada[i++] - 'A';
                grafo[v].push_back(n);
            }
        }
        dfs(t, m, grafo, marcado, resposta);
        if (resposta.size() == 1) printf("/%c", resposta[0] + 'A');
        else {
            printf("%c", resposta[0] + 'A');
            for (int i = 1; i < resposta.size() - 1; i++) printf(" %c", resposta[i] + 'A');
            printf(" /%c", resposta[resposta.size() - 1] + 'A');
        }
        printf("\n");
    }
    return 0;
}
