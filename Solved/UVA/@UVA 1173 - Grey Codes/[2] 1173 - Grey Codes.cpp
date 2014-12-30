#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, x, y;

int greyCodeInverse(int n) { 
	int temp = n >> 1;
	while(temp) {
		n ^= temp;
		temp = temp >> 1;
	}
	return n;
}

int main() {
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&x);
		printf("%d\n",greyCodeInverse(x));
	}
}
