//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1144

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef pair<int,int> ii;

// Meters / Minute
const double velocity = 20000.0 / 60.0;

char word[100];
ii source;

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%d %d\n",&source.first,&source.second);
		double sum = 0.0;
		while(fgets(word,100,stdin) && word[0] != '\n') {
			ii x, y;
			char *f = strtok(word," ");
			x.first = atoi(f); f = strtok(NULL, " ");
			x.second = atoi(f); f = strtok(NULL, " ");
			y.first = atoi(f); f = strtok(NULL, " ");
			y.second = atoi(f);
			sum += hypot(x.first-y.first,x.second-y.second);
		}
		sum *= 2.0;
		int minutes = round(sum / velocity);
		int hours = minutes / 60;
		minutes = minutes - ((minutes / 60) * 60);
		printf("%d:%02d\n",hours,minutes);
		if(T)
			puts("");
	}
}
