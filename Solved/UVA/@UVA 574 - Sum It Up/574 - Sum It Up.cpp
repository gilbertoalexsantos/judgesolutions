//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=515

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

map<string,bool> m;
vector<int> flag;
bool ok;

void print() {
	printf("%d",flag[0]);
	for(int i = 1; i < flag.size(); i++) printf("+%d",flag[i]);
	printf("\n");
}

bool check() {
	stringstream s;	
	for(int i = 0; i < flag.size(); i++) s << flag[i];
	string temp = s.str();

	if(m[temp]) return false;
	m[temp] = 1;
	return true;
}

void backtrack(int t, int size, int arr[], int pos = 0, int sum = 0) {
	if(sum > t) return;
	
	if(sum == t && check()) {
		if(!ok) printf("Sums of %d:\n",t);
		print();
		ok = true;
		return;
	}

	if(pos == size) {
		if(sum == t && check()) {
			if(!ok) printf("Sums of %d:\n",t);
			print();
			ok = true;
		}
		return;
	}

	for(int i = pos; i < size; i++) {
		flag.push_back(arr[i]);
		backtrack(t,size,arr,i+1,sum + arr[i]);
		flag.pop_back();
	}
}

void clear() {
	flag.clear();
	m.clear();
	ok = false;
}

int main() {
	int t, n;
	while(scanf("%d %d",&t, &n) && n) {
		clear();
		int arr[n];
		for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
		backtrack(t,n,arr);
		if(!ok) printf("Sums of %d:\nNONE\n",t);
	}
}
