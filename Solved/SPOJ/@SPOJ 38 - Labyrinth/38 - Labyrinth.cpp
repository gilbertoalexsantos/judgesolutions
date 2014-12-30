//Author:	Gilberto A. dos Santos
//Website:	http://www.spoj.com/problems/LABYR1/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 1001

int dl[4] = {0, 1,  0, -1};
int dc[4] = {1, 0, -1,  0};

int n, line, row, resp, flag, vx, vy;
char grid[MAX][MAX];
bool check[MAX][MAX];

void dfs(int x, int y) {
	if(x < 0 || y < 0 || x >= line || y >= row) {
		flag--;
		return;
	}

	check[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int nline = x + dl[i], nrow = y + dc[i];
		if(!check[nline][nrow] && grid[nline][nrow] == '.') {
			flag++;
			dfs(nline,nrow);
		}
	}
    if(resp < flag) {
		resp = flag;
		vx = x;
		vy = y;
    }
	flag--;
}

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &row, &line);

        for(int l = 0; l < line; l++)
            scanf("%s", grid[l]);

		vx = 0, vy = 0;
		bool ok = false;
		for(int i = 0; i < line; i++) {
			for(int j = 0; j < row; j++) {
				if(grid[i][j] == '.') {
					vx = i; vy = j;
					ok = true; break;
				}
			}
			if(ok) break;
		}

		memset(check,0,sizeof check);
		resp = flag = 0;
		dfs(vx,vy);

		if(resp) {
			memset(check,0,sizeof check);
			resp = flag = 0;
			dfs(vx,vy);
            printf("Maximum rope length is %d.\n", resp);
		} else printf("Maximum rope length is 0.\n");
    }
}
