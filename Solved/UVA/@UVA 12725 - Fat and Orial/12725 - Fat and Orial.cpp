//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4577

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int qt, cases = 1;
	scanf("%d",&qt);
	while(qt--) {
		double n, m;
		int a, b;
		scanf("%lf %lf %d %d",&n,&m,&a,&b);
	
		int divi = a+b;
		double n_f1 = (double) n*a;
		double n_f2 = (double) m*divi;
		double ans = (double) (n_f2 - n_f1)/(double) b;

		(ans > 10.000 || ans < 0) ? printf("Case #%d: Impossible\n",cases++) : printf("Case #%d: %.2lf\n",cases++,ans);
	}
}
