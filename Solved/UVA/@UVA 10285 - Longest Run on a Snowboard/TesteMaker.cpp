#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAX = 100;

int g() { return abs(rand()%100); }

int main() {
	printf("15\n");
	srand(time(NULL));
	for(int i = 0; i < 15; i++) {
		printf("MrBluesmann %d %d\n",MAX,MAX);
		for(int i = 0; i < MAX; i++) {
			printf("%d",g());
			for(int j = 1; j < MAX; j++) {
				printf(" %d",g());
			}
			printf("\n");
		}
	}
}
