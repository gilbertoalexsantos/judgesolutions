//Author:	Gilberto A. dos Sants
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=382

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void lexico(int arr[], int size) {
	for(int a = 0; a < size - 5; a++)
		for(int b = a+1; b < size - 4; b++)
			for(int c = b+1; c < size - 3; c++)
				for(int d = c+1; d < size - 2; d++)
					for(int e = d+1; e < size - 1; e++)
						for(int f = e+1; f < size; f++)
							printf("%d %d %d %d %d %d\n",arr[a],arr[b],
									arr[c],arr[d],arr[e],arr[f]);
		
}

int main() {
	bool first = true;
	int k;
	while(scanf("%d",&k) && k) {
		if(first) first = false;
		else printf("\n");
		int arr[k];
		for(int i = 0; i < k; i++) scanf("%d",&arr[i]);
		lexico(arr,k);
	}
}
