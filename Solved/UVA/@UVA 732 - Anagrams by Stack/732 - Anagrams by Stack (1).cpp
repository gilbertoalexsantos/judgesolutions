//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=673

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

void anagram(string a, string b, string s, string r) {
	if(a.empty() && b.empty() && s.empty()) {
		r.erase(r.size() - 1,1);
		cout << r << endl;
		return;
	}

	//PUSH
	if(!a.empty()) {
		anagram(a.substr(1,a.size() - 1),b,a[0] + s,r + "i ");
	}

	//POP
	if(!s.empty() && s[0] == b[0]) {
		anagram(a,b.substr(1,b.size() - 1),s.substr(1,s.size() - 1),r + "o ");
	}
}

int main() {
	string a, b;
	while(cin >> a >> b) {
		printf("[\n");
		anagram(a,b,"","");
		printf("]\n");
	}
}