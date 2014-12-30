//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3544

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int WHITE = 0, BLACK = 1, MARKED_HOLE = 2, MARKED_BLACK = 3, BACKGROUND = 9;
const int MAX_ROW = 203, MAX_COL = 53;
const int dr[] = {0,1, 0,-1};
const int dc[] = {1,0,-1, 0};
const char hiero[] = {'W','A','K','J','S','D','\0'};

vector<char> ans;
char m[MAX_ROW][MAX_COL];
int nm[MAX_ROW][MAX_COL*4];
int qt_row, qt_col;

void clear() {
	ans.clear();
}

inline bool checkRange(int x, int y) { return (x >= 0 && x < qt_row && y >= 0 && y < qt_col); } 
inline int parseHexaInt(char c) { return (c >= '0' && c <= '9') ? c-'0' : c-'a'+10; }

void transform() {
	for(int i = 0; i < qt_row; i++) {
		for(int j = 0, pos = 0; j < qt_col; j++) {
			int n = parseHexaInt(m[i][j]);
			for(int z = 3; z >= 0; z--) nm[i][pos++] = (n & (1 << z)) ? 1 : 0;
		}
	}
	qt_col *= 4;
}

void flood1(int x, int y, int color) {
	if(!checkRange(x,y) || nm[x][y] != WHITE) return;
	nm[x][y] = color;
	for(int i = 0; i < 4; i++) flood1(x+dr[i],y+dc[i],color);
}

int flood2(int x, int y, int color) {
	if(!checkRange(x,y) || (nm[x][y] != BLACK && nm[x][y] != WHITE)) return 0;
	
	if(nm[x][y] != WHITE) nm[x][y] = color;

	int ret = 0;
	if(nm[x][y] == WHITE) {
		ret++;
		flood1(x,y,MARKED_HOLE);
	}
	
	for(int i = 0; i < 4; i++) ret += flood2(x+dr[i],y+dc[i],color);

	return ret;
}

void color_border() {
	for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++)
		if(i == 0 || i == qt_row-1 || j == 0 || j == qt_col-1)
			flood1(i,j,BACKGROUND);
}

void solve() {
	for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++) {
		if(nm[i][j] == BLACK) {
			int qt_hole = flood2(i,j,MARKED_BLACK);
			ans.push_back(hiero[qt_hole]);
		}
	}
}


int main() {
	int cases = 1;
	while(scanf("%d %d",&qt_row,&qt_col) && qt_row+qt_col) {
		clear();
		for(int i = 0; i < qt_row; i++) scanf("%s",m[i]);

		transform();
		color_border();
		solve();

		sort(ans.begin(),ans.end());
		printf("Case %d: ",cases++);
		for(int i = 0; i < ans.size(); i++) printf("%c",ans[i]);
		printf("\n");
	}
}
