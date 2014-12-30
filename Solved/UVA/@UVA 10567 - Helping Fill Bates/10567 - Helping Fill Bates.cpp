//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1508

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator IT;
#define MAX 1000001

vector<vector<int> > arr;

int main() {
	char w[MAX];
	int qt;
	scanf("%s %d",w,&qt);
	arr.resize(53);
	int i = -1;
	while(w[++i]) {
		int pos = (w[i] >= 97) ? w[i] - 71 : w[i] - 65;
		arr[pos].push_back(i);
	}
	while(qt--) {
		char ss[103];
		scanf("%s",ss);
		bool ok = true;
		int first = 0, last = 0, j = 0, l_pos = -1;
		while(ss[j]) {
			int pos = (ss[j] >= 97) ? ss[j] - 71 : ss[j] - 65;
			IT it = upper_bound(arr[pos].begin(),arr[pos].end(),l_pos);
			if(it == arr[pos].end()) {
				ok = false;
				break;
			}
			int ret = arr[pos][it - arr[pos].begin()];
			if(!j) first = ret;
			if(!ss[j+1]) last = ret;
			l_pos = ret, j++;
		}
		ok ? printf("Matched %d %d\n",first,last) : printf("Not matched\n");
	}
}
