//Author:   Gilberto Alexandre dos Santos
//Website:  http://www.spoj.com/problems/CRDS/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef unsigned long long ull;
int n;

ull calc(ull number) {
	ull a1 = 3;
	ull razao = 3;
	ull an = a1 + (number - 1) * razao;
	return ((((a1 + an) * number) / 2) - number) % 1000007;
}

int main() {
	scanf("%d", &n);
	while(n--) {
		ull temp;
		scanf("%llu", &temp);
		printf("%llu\n",calc(temp));
	}
}
