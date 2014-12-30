//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3503

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string entry;
vector<stack<char> > container;

int main() {
	int _case = 1;
	while(cin >> entry && entry != "end") {
		int ans = 1;
		stack<char> temp;
		temp.push(entry[0]);
		container.push_back(temp);
		for(int i = 1; i < entry.size(); i++) {
			bool cat = false;
			for(int j = 0; j < container.size(); j++) {
				if(container[j].top() >= entry[i]) {
					cat = true;
					container[j].push(entry[i]);
					break;
				}
			}
			if(!cat) {
				stack<char> temp;
				temp.push(entry[i]);
				container.push_back(temp);
				ans++;
			}
		}
		container.clear();
		printf("Case %d: %d\n",_case++,ans);
	}
}
