//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3084

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int const MAX = 1 << 31;
int n;

int getNumber(bool type) {
	int temp = 0, ans = n, flag;
	bool get = type;
	while((flag = 1 << temp) <= n && temp < 31) {
		if(n & flag) { 
			if(!get) ans &= ~flag;
			get = !get;
		}
		temp++;
	}
	return ans;
}

int main() {
	while(scanf("%d",&n) && n) {
		printf("%d %d\n",getNumber(true),getNumber(false));
	}
}
