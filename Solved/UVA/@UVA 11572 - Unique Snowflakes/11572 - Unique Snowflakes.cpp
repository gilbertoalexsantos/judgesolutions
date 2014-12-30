//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2619

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

int n, snowflakes;
int arr[1000001];

int main() {
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&snowflakes);
		int ans = 0;
		int flag = 0;
		map<int, int> m;
		for(int i = 1; i <= snowflakes; i++) scanf("%d",&arr[i]);	

		int pos = 1;
		int i = 1;
		while(i <= snowflakes) {
			if(!m[arr[i]]) {
				m[arr[i]] = i;	
				flag++;
				i++;
			} else {
				int last = m[arr[i]];
				flag = i - last;
				while(pos < last) m[arr[pos++]] = 0;
				m[arr[i]] = i;
				i = i+1;
				pos = last+1;
			}
			ans = max(flag,ans);
		}

		cout << ans << endl;
	}
}
