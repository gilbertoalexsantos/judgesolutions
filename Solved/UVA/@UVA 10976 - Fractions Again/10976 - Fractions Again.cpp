//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1917

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pint;

void getFraction(int k) {
	vector<pint> arr;
	int count = 0;
	for(int i = k+1, cont = 1; i <= k*2; i++,cont++) {
		if(!((i*k) % cont)) {
			pint temp;
			temp.first = (i*k)/cont;
			temp.second = i;
			arr.push_back(temp);
		}
	}
	printf("%lu\n",arr.size());
	for(int i = 0; i < arr.size(); i++)
		printf("1/%d = 1/%d + 1/%d\n",k,arr[i].first,arr[i].second);
}

int main() {
	int k;
	while(scanf("%d",&k) != EOF) {
		getFraction(k);
	}
}
