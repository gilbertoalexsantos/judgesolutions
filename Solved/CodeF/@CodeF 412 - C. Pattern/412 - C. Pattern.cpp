//Author:	Gilberto A. dos Santos
//Website:	http://codeforces.com/contest/412/problem/C

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 100005;
const char PATTERN = 'a', GUESS = '?';

char grid[MAX];
char flag[MAX];
bool has[MAX];

int main() {
	memset(has,false,sizeof has);
	memset(flag,PATTERN,sizeof flag);
	int n, len = -1;
	scanf("%d",&n);

	for(int i = 0; i < n; i++) {
		scanf("%s",grid);

		if(len == -1) len = strlen(grid);

		for(int j = 0; j < len; j++) {
			if(flag[j] == GUESS || grid[j] == GUESS) continue;

			if(!has[j]) {
				has[j] = true;
				flag[j] = grid[j];
			} else if(grid[j] != flag[j])
				flag[j] = GUESS;
		}

	}

	for(int i = 0; i < len; i++) printf("%c",flag[i]);
	printf("\n");
}
