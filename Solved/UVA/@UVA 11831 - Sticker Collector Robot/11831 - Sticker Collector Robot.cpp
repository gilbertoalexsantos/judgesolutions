//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2931

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef pair<int,int> pint;

const char NORMAL = '.', STICKER = '*', PILLAR = '#';
const char NORTH = 'N', SOUTH = 'S', EAST = 'L', WEST = 'O';
const char RIGHT = 'D', LEFT = 'E', FORWARD = 'F';

int qt_row, qt_col;
char m[101][101];
char direction[50001];
int size_direction;

pint getEqui(char c) {
	if(c == NORTH) return pint(-1,0); if(c == SOUTH) return pint(1,0);
	if(c == WEST) return pint(0,-1); if(c == EAST) return pint(0,1);
	return pint(-1,-1);
}

char getOri(char c, char ori) {
	if(c == NORTH) return ori == RIGHT ? EAST : WEST;
	else if(c == SOUTH) return ori == RIGHT ? WEST : EAST;
	else if(c == WEST) return ori == RIGHT ? NORTH : SOUTH;
	else return ori == RIGHT ? SOUTH : NORTH;
}

int dfs(int x, int y, char ori, int pos = 0) {
	int ans = 0;
	if(m[x][y] == STICKER) {
		ans = 1;
		m[x][y] = '.';
	}

	if(pos == size_direction) return ans;

	if(direction[pos] == FORWARD) {
		pint ndir = getEqui(ori);
		int nx = x+ndir.first, ny = y+ndir.second;
		if(nx < 0 || nx >= qt_row || ny < 0 || ny >= qt_col || m[nx][ny] == PILLAR)
			return ans + dfs(x,y,ori,pos+1);
		else return ans+dfs(nx,ny,ori,pos+1);
	} else return ans + dfs(x,y,getOri(ori,direction[pos]),pos+1);

}

int main() {
	int s;
	while(scanf("%d %d %d",&qt_row,&qt_col,&s) && qt_row+qt_col+s) {
		for(int i = 0; i < qt_row; i++) scanf("%s",m[i]);
		scanf("%s",direction);
		size_direction = strlen(direction);

		// Getting INIT POS
		int beg_row, beg_col;
		char beg_ori;
		for(int i = 0; i < qt_row; i++) for(int j = 0; j < qt_col; j++) {
			char c = m[i][j];
			if(c == NORTH || c == SOUTH || c == EAST || c == WEST) {
				beg_ori = c;
				beg_row = i, beg_col = j;
				break;
			}
		}

		int ans = dfs(beg_row,beg_col,beg_ori);
		printf("%d\n",ans);
	}
}
