//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1205

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;	

int n;
int debug;

int main() {
	while(scanf("%d",&n) != EOF) {
		int N = pow(2,n);
		int edge[N];
		int sum[N];
		int resp = -1;
		for(int i = 0; i < N; i++) scanf("%d",&edge[i]);
		for(int i = 0; i < N; i++) {
			int t = 0;
			for(int j = 0; j < n; j++) 
				t += edge[i ^ (1 << j)];
			sum[i] = t;
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < n; j++)
				resp = max(resp,sum[i] + sum[i ^ (1 << j)]);
		printf("%d\n",resp);
	}
}
