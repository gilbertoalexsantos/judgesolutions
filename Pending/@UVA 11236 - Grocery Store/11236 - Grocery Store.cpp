//Author:	Gilberto A. dos Santos
//Website:	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2177

#include <cstdio>
#include <cstdlib>
#include <cmath>

typedef long long ll;

int main () {
	for (ll a = 1; a <= 2000; a ++) {
		for (ll b = a; b <= 2000; b ++) {
			double tempa = a / 100.0;
			double tempb = b / 100.0;
			if((tempa * tempb > 2000)) continue;
			for (ll c = b; c <= 2000; c ++) {
				ll sum = a+b+c;
				ll mult = a*b*c;

				if (mult <= 1e6) continue;

				if(mult - 1 <= 0) continue;
				double A = a / 100.0;
				double B = b / 100.0;
				double C = c / 100.0;
				double D = (double) sum / (mult - 1.00) / 100.0;
						if(A+B+C+D <= 20.00) printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", a/100.0, b/100.0, c/100.0, d/100.0);
				//ll d = (1e6 * sum) / (mult - 1e6);
/*
				if (d >= c && sum+d <= 2000) {
					double A = a / 100.0;
					double B = b / 100.0;
					double C = c / 100.0;
					double D = d / 100.0;

					double n_sum = A+B+C+D;    
					double n_mult = A*B*C*D;;

					if (fabs(n_sum - n_mult) < 1e-9)
						printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", a/100.0, b/100.0, c/100.0, d/100.0);
						*/
				}
			}
		}
	}
}
