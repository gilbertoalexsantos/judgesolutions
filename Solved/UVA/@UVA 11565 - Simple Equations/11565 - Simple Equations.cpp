//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2612

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

bool hasSol(int &x, int &y, int &z, int A, int B, int C) {
	for(x = -100; x <= 100; x++) {
		if(!x) continue;
		if(B%x) continue;
		for(y = -100; y <= 100; y++) {
			if(!y) continue;
			if(B%y || x*y > B || x == y) continue;
			for(z = -100; z <= 100; z++) {
				if(!z || x == z || y == z) continue;
				if(x+y+z == A && x*y*z == B && pow(x,2)+pow(y,2)+pow(z,2) == C) return true;
			}
		}
	}
	return false;
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		int A, B, C, x, y, z;
		scanf("%d %d %d",&A,&B,&C);
		if(hasSol(x,y,z,A,B,C)) printf("%d %d %d\n",x,y,z);
		else printf("No solution.\n");
	}
}
