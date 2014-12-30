//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2261

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <ios>
#include <map>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	while(cin >> n && n) {
		map<string,int> m;
		int ans = 0;
		int high = 1;
		for(int i = 0; i < n; i++) {
			vector<string> temp(5);
			for(int j = 0; j < 5; j++) cin >> temp[j];
			sort(temp.begin(),temp.end());
			string conc = "";
			for(int j = 0; j < 5; j++) conc += temp[j];

			if(m[conc]) {
				int r = ++m[conc];
				if(r > high) {
					high = r;
					ans = high;
				} else if(r == high) ans += high;
			} else {
				m[conc] = 1;
				if(high == 1) ans++;
			}
		}
		cout << ans << endl;
	}
}
