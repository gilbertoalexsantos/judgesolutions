// Author: Gilberto A. dos Santos
// Website: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2114

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, x, y;

int greyCode(int n) { return n ^ (n >> 1); }

int main() {
	scanf("%d",&n);
	while(n--) {
		scanf("%d %d",&x, &y);
		printf("%d\n",greyCode(y));
	}
}
