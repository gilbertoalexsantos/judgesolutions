//Author:	Gilberto A. dos Santos
//Website:	http://br.spoj.com/problems/TESOURO/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int j1, j2, n;
int ele[100 + 1];

int knapsack(int size) {
	bool knap[size + 1];
	memset(knap,0,sizeof knap);
    knap[0] = true;
    
    int sum = 0;
	for(int i = 0; i < n; i++) {
        sum += ele[i];
		for(int j = min(size, sum); j >= ele[i]; j--)
            if(knap[j - ele[i]]) knap[j] = true;
        if(knap[size]) return true;
    }

	return false;
}

int main() {
	int cases = 1;
	bool first = true;
	while(true) {
		scanf("%d %d %d",&j1, &j2, &n);
		if(!j1) break;
		else if(!first) printf("\n");
		else first = false;
        
		int sum = 0;
		memset(ele,0,sizeof ele);
		for(int i = 0; i < n; i++) {
			scanf("%d",&ele[i]);
			sum += ele[i];
		}
        
		if((j1 + j2 + sum) % 2) {
			printf("Teste %d\n",cases++);
			printf("N\n");
			continue;
		}
        
		int req;
		int r1 = ((j1 + j2 + sum) / 2) - j1;
		int r2 = ((j1 + j2 + sum) / 2) - j2;
		if(r1 < 0) req = r2;
		else if(r2 < 0) req = r1;
		else req = min(r1,r2);

		printf("Teste %d\n",cases++);
		if(knapsack(req)) printf("S\n");
		else printf("N\n");
	}
}

