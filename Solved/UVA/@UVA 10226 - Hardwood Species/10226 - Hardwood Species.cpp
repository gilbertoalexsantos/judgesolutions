//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1167

#include <iostream>
#include <ios>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
int debug;

int main() {
	ios::sync_with_stdio(false);
	cout << setprecision(4) << fixed;

	cin >> n;
	cin.ignore();
	cin.ignore();

	bool first = true;
	while(n--) {

		if(first) first = false;
		else cout << endl;

		vector<string> v;
		map<string, int> m;

		string temp;
		int size = 0;
		while(getline(cin,temp) && temp != "") {
			size++;
			if(m[temp]) m[temp]++;
			else {
				v.push_back(temp);
				m[temp] = 1;
			}
		}

		sort(v.begin(),v.end());

		for(int i = 0; i < v.size(); i++) {
			cout << v[i]; 
			float ans = (float) (m[v[i]] * 100) / size;
			cout << " " << ans << endl;
		}
	}
}
