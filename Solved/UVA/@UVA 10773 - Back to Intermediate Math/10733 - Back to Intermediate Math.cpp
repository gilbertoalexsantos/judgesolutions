//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1714

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int width, river_speed, boat_speed;

int main() {
	int cases = 1, T; scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&width,&river_speed,&boat_speed);
		printf("Case %d: ",cases++);
		if(boat_speed <= river_speed || river_speed == 0 || boat_speed == 0)
			printf("can't determine\n");
		else {
			double fastest = (double) width / boat_speed;
			double shortest = (double) width / sqrt(pow(boat_speed,2) - pow(river_speed,2));
			printf("%.3lf\n",fabs(fastest - shortest));
		}
	}
}
