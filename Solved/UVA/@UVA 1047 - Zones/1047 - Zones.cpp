//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3488

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,int> ii;

int main() {
	int qt_tower, qt_built, cases = 1;
	while(scanf("%d %d",&qt_tower,&qt_built) && qt_tower+qt_built) {

		int tower[qt_tower];
		for(int i = 0; i < qt_tower; i++) scanf("%d",&tower[i]);

		int qt_common;
		scanf("%d",&qt_common);
    vector<ii> m(qt_common);
		for(int i = 0; i < qt_common; i++) {
			int qt;
			scanf("%d",&qt);

			int pos = 0;
			for(int j = 0; j < qt; j++) {
				int temp;
				scanf("%d",&temp);
				pos |= (1 << (temp-1));
			}

			int value;
			scanf("%d",&value);
      m[i] = ii(pos,value);
		}

		int ans = 0, flagMax = -1e9;
		for(int i = 0; i < (1 << qt_tower); i++) {
			if(__builtin_popcount(i) != qt_built) 
        continue;

			int temp = 0;
			for(int j = 0; j < qt_tower; j++)
				if(i & (1 << j)) temp += tower[j];

      for(int j = 0; j < m.size(); j++) {
        int pos = m[j].first, val = m[j].second;
				int qt_1 = __builtin_popcount(i & pos);
				if(qt_1 >= 2) temp -= (qt_1-1) * val;
			}

			if(temp > flagMax) {
				flagMax = temp;
				ans = i;
			}
		}

		printf("Case Number  %d\n",cases++);
		printf("Number of Customers: %d\n",flagMax);
		printf("Locations recommended:");
		for(int i = 0; i <= qt_tower; i++) if(ans & (1 << i)) printf(" %d",i+1);
		printf("\n\n");
	}
}
