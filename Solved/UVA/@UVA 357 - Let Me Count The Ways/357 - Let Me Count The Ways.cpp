//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=293

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef unsigned long long ll;

ll memo[30000+1];
int arr_coin[5] = {1,5,10,25,50};
int size = 5;


int main() {
	memset(memo,0,sizeof memo);
	memo[0] = 1;
	for(int i = 0; i < 5; i++)
		for(int j = arr_coin[i]; j <= 30000; j++)
			memo[j] += memo[j-arr_coin[i]];
	int n;
	while(scanf("%d",&n) != EOF) {
		ll ans = memo[n];
		bool plus = ans == 1;
		char w[2][11] = {{"are"},{"is only"}};
		printf("There %s %llu %s to produce %d cents change.\n",w[plus],ans,plus ? "way" : "ways",n);
	}
}
