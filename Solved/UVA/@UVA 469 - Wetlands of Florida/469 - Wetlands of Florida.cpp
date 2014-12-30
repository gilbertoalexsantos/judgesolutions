//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=410

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef pair<int,int> pint;

const int MAX = 105;
const int dr[] = {1,1,0,-1,-1,-1,0,1};
const int dc[] = {0,1,1,1,0,-1,-1,-1};

int size_row, size_col;
int color[MAX][MAX];

char m[MAX][MAX];

int flood_fill(int x, int y, int new_color) {
	if(x < 0 || x >= size_row || y < 0 || y >= size_col) return 0;
	if(m[x][y] == 'L' || color[x][y] == new_color) return 0;
	color[x][y] = new_color;
	int ans = 1;
	for(int i = 0; i < 8; i++) ans += flood_fill(x+dr[i],y+dc[i],new_color);
	return ans;
}

void clear() {
	memset(color,-1,sizeof color);
}

int main() {
	int T;
	scanf("%d\n\n",&T);
	while(T--) {
		clear();
		size_row = 0;
		while(fgets(m[size_row],MAX,stdin)  && (m[size_row][0] == 'L' 
				|| m[size_row][0] == 'W') && m[size_row][0] != '\n') 
			size_row++;

		size_col = strlen(m[0])-1;

		if(m[size_row][0] == '\n') continue;

		char *f = strtok(m[size_row]," ");
		int x, y;
		x = atoi(f);
		f = strtok(NULL," ");
		y = atoi(f);
		x--, y--;

		int n_color = 0;
		vector<int> save_color;
		
		int ans = flood_fill(x,y,n_color++);
		save_color.push_back(ans);
		printf("%d\n",ans);

		char w[20];
		while(fgets(w,20,stdin) && w[0] != '\n') {
			char *A = w, *B = w+2;
			x = atoi(A), y = atoi(B);
			x--, y--;
			if(color[x][y] != -1) ans = save_color[color[x][y]];
			else {
				ans = flood_fill(x,y,n_color++);
				save_color.push_back(ans);
			}
			printf("%d\n",ans);
		}
		if(T) printf("\n");
	}
}
