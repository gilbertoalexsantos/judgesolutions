//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=82

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string word;

int main() {
	while(cin >> word && word != "#") {
		string next = word, answer;
		bool catou = false;
		do {
			if(catou) {
				answer = word;
				break;
			}
			if(word == next) catou = true;	
		} while(next_permutation(word.begin(),word.end()));
		if(answer.empty()) printf("No Successor\n");
		else cout << answer << endl;
	}
}
