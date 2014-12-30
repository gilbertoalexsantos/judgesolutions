//Author: Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=691

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;

int n;
int cont;
int x, y;
int times;
vector<int> resp;

bool verifica(int board[], int linha, int coluna) {
    for (int c = 0; c < coluna; c++) {
        if (board[c] == linha) return false;
        if (abs(linha - board[c]) == abs(coluna - c)) return false;
    }
    return true;
}

void backtrack(int board[], int coluna) {
    if (coluna < n) {
        if (coluna != y) {
            for (int linha = 0; linha < n; linha++) {
                if (verifica(board, linha, coluna)) {
                    board[coluna] = linha;
                    backtrack(board, coluna + 1);
                }
            }
        } else if (verifica(board, x, y)) backtrack(board, coluna + 1);
    } else {
        printf("%2d      %d", cont++, board[0] + 1);
        // Encontrou 1 resultado
        for (int i = 1; i < n; i++) printf(" %d", board[i] + 1);
        puts("");
    }
}

int main() {
    n = 8;
    scanf("%d", &times);
    while (times--) {
        cont = 1;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        int board[n];
        for (int i = 0; i < n; i++) board[i] = -1;
        board[y] = x;
        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8\n");
        backtrack(board, 0);
        if (times) puts("");
    }
    return 0;
}
