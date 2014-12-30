//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2026

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

// board[i] = j
// i = collumn
// j = row
int board[8], flag[8];

int check(int line, int col) {
	for(int c = 0; c < col; c++) {
		if(flag[c] == line) return false;
		if(abs(flag[c] - line) == abs(col - c)) return false;
	}
	return true;
}

int backtrack(int col) {
	if(col >= 8) return 0;
	int t = 1e9;
	for(int line = 0; line < 8; line++) {
		if(!check(line,col)) continue;
		flag[col] = line;
		t = min(t, (line == board[col]) ? backtrack(col+1) : 1 + backtrack(col+1));
	}
	return t;
}

int main() {
	int cases = 1;
	while(scanf("%d %d %d %d %d %d %d %d",&board[0],&board[1],&board[2],&board[3],&board[4],&board[5],&board[6],&board[7]) != EOF) {
		for(int i = 0; i < 8; i++) board[i]--;
		printf("Case %d: %d\n",cases++,backtrack(0));
	}
}
