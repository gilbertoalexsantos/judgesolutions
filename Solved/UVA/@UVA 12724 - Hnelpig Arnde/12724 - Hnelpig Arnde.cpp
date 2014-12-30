//Author:   Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4576

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct type {
	char w[41], sorted[41];

	type() {}
	type(char t[]) {
		strcpy(w,t);
		sort(t,t+strlen(t));
		strcpy(sorted,t);
	}
};

struct cc {
	char w[41];
	cc(char t[]) { strcpy(w,t); }
};

int main() {
	int qt, cases = 1;
	scanf("%d",&qt);
	while(qt--) {
		int n, m;
		scanf("%d %d",&n, &m);

		vector<vector<type> > matrix;
		matrix.resize(256);

		for(int i = 0; i < n; i++) {
			char temp[41];
			scanf("%s",temp);
			type t(temp);
			matrix[t.sorted[0]].push_back(t);
		}
		getchar();

		printf("Case #%d:\n",cases++);
		while(m--) {
			vector<cc> ans;
			char word[5000];
			scanf("%[^\n]s",word);
			getchar();

			char *flag = strtok(word," ");
			while(flag != NULL) {
				sort(flag,flag+strlen(flag));
				for(int i = 0; i < matrix[flag[0]].size(); i++) {
					if(!strcmp(flag,matrix[flag[0]][i].sorted)) {
						cc t(matrix[flag[0]][i].w);		
						ans.push_back(t);
						break;
					}
				}
				flag  = strtok(NULL," ");
			}

			printf("%s",ans[0].w);
			for(int i = 1; i < ans.size(); i++) printf(" %s",ans[i].w);
			printf("\n");
		}

	}
}
