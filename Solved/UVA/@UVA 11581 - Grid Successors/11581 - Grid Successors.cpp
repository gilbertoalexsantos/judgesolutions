//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2628

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <bitset>
using namespace std;

int n;

int dl[4] = {1,-1,3,-3};
bitset<9> grid;
int debug;

bool can(int x, int y) {
	if(!((x+1) % 3) && (y == 1)) return false;
	if(!(x % 3) && (y == -1)) return false;
	return true;
}

int getMax(int pos) {
	int ret = 0;
	for(int i = 0; i < 4; i++)
		if((pos + dl[i]) >= 0 && (pos + dl[i]) < 9) {
			if(can(pos,dl[i]))
				if(grid[pos + dl[i]]) ret += 1;
		}
	return ret;
}

int alg() {
	int ret = -1;
	if(grid.none()) return -1;
	while(true) {
		ret++;
		bitset <9> temp;
		for(int i = 0; i < 9; i++) temp[i] = getMax(i) % 2;
		if(temp.none()) break;
		grid = temp;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	while(n--) {
		string flag;
		for(int i = 0; i < 3; i++) {
			string t;
			cin >> t;
			flag += t;	
		}
		bitset<9> temp(flag);
		grid = temp;
		printf("%d\n",alg()); 
		grid.reset();
	}
}
