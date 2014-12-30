#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

inline int g(int n) { return abs(rand()%n); }

const int VERT = 30;
const int EDGE = 500;
const int STORE = 5;
const int MAX_DIST = 1000;
const int MAX_SAVE = 7000;

int main() {
	srand(time(NULL));
	printf("1\n");
	printf("%d %d\n",VERT,EDGE);
	for(int i = 0; i < EDGE; i++) {
		if(i == 0) {
			int p1 = g(VERT), p2 = g(MAX_DIST), p3 = g(100);
			printf("0 %d %d.%d\n",p1,p2,p3);
			continue;
		}
		int p1 = g(VERT), p2 = g(VERT), p3 = g(MAX_DIST), p4 = g(100);
		printf("%d %d %d.%d\n",p1,p2,p3,p4);
	}
	printf("%d\n",STORE);
	for(int i = 0; i < STORE; i++) {
		int p1 = g(VERT), p2 = g(MAX_SAVE), p3 = g(100);
		printf("%d %d.%d\n",p1,p2,p3);
	}
}
