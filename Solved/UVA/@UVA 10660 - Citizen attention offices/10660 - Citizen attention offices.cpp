//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1601

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

inline int mt(int x0, int y0, int x1, int y1) { return abs(x0 - x1) + abs(y0 - y1); }
inline int nMin(int a, int b, int c, int d, int e) { return min(min(min(min(a,b),c),d),e); }

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--) {
		int n;
		scanf("%d",&n);

		int m[25];
		memset(m,0,sizeof m);

		for(int i = 0; i < n; i++) {
			int l, c, v;
			scanf("%d %d %d",&l,&c,&v);
			m[l*5 + c] = v;
		}

		int minSum = 100000000;
		int ans[5];
		for(int a = 0; a < 25; a++)
			for(int b = a+1; b < 25; b++)
				for(int c = b+1; c < 25; c++)
					for(int d = c+1; d < 25; d++)
						for(int e = d+1; e < 25; e++) {
							int sum = 0;
							for(int f = 0; f < 25; f++) {
								int row = f/5;
								int col = f%5;
								int da = mt(row,col,a / 5, a % 5) * m[f];
								int db = mt(row,col,b / 5, b % 5) * m[f];
								int dc = mt(row,col,c / 5, c % 5) * m[f];
								int dd = mt(row,col,d / 5, d % 5) * m[f];
								int de = mt(row,col,e / 5, e % 5) * m[f];
								sum += nMin(da,db,dc,dd,de);
							}
							if(sum < minSum) {
								minSum = sum;
								ans[0] = a, ans[1] = b, ans[2] = c, ans[3] = d, ans[4] = e;
							}
						}
		printf("%d",ans[0]);
		for(int i = 1; i < 5; i++) printf(" %d",ans[i]);
		printf("\n");
	}
}
