//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=868

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

#define FOR(var,from,to) for(int var = from; var <= to; var++)
typedef unsigned long long ull;

int C, d, k, degree;
int polynomin[21];

ull next(int pos) {
	ull ans = 0;
	FOR(i,0,degree) ans += (unsigned long long) polynomin[i] * pow(pos,i);
	return ans;
}

int getK() {
	int count = 1;
	int ans = 1;
	int right = 0;
	while(true) {
		right += count * d;
		if(right < k) ans++;
		else break;
		count++;
	}
	return ans;
}

int main() {
	scanf("%d",&C);
	while(C--) {
		scanf("%d",&degree);
		FOR(i,0,degree) scanf("%d",&polynomin[i]);
		scanf("%d %d",&d, &k);
		printf("%llu\n",next(getK()));
	}
}
