//Author:	Gilberto A. dos Santos
//Website:	http://www.urionlinejudge.com.br/judge/en/problems/view/1018

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int notes[] = {100, 50, 20, 10, 5, 2, 1};
const int size = sizeof notes / sizeof notes[0];

int n;

int main() {
	scanf("%d",&n);	
	printf("%d\n",n);
	for(int i = 0; i < size; i++) {
		int ans = n / notes[i];
		n -= (ans * notes[i]);
		printf("%d nota(s) de R$ %d,00\n",ans,notes[i]);
	}
}
