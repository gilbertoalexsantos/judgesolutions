//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=673

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

string a, b;
stack<char> s;

void anagram(int x, int y, string r) {
	if(x == a.size() && y == b.size() && s.empty()) {
		r.erase(r.size() - 1,1);
		cout << r << endl;
		return;
	}

	//PUSH
	if(x < a.size()) {
		s.push(a[x]);
		anagram(x+1,y,r + "i ");
		s.pop();
	}

	//POP
	if(!s.empty() && s.top() == b[y]) {
		char temp = s.top();
		s.pop();
		anagram(x,y+1,r + "o ");
		s.push(temp);
	}
}

int main() {
	while(cin >> a >> b) {
		printf("[\n");
		anagram(0,0,"");
		while(!s.empty()) s.pop();
		printf("]\n");
	}
}
