//Author: Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=861

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<math.h>
using namespace std;

struct cord {
    float x;
    float y;
};

struct reta {
    float a;
    float b;
};

int c;

bool comp(cord i, cord j) {
    return (i.x > j.x);
}

float distancia(cord a, cord b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}

reta ret(cord q, cord w) {
    float m = ((w.y - q.y) / (w.x - q.x));
    reta result;
    result.a = m;
    result.b = w.y - (m * w.x);
    return result;
}

float pontox(reta r, float pontoy) {
    return (pontoy - r.b)/r.a;
}

int main() {
    scanf("%d", &c);
    while (c--) {
        int n;
        scanf("%d", &n);
        cord m[n];
        for (int i = 0; i < n; i++)
            scanf("%f %f", &m[i].x, &m[i].y);
        sort(m, m + n, comp);
        float max = 0, sum = 0;
        int cont = 1;
        while (m[cont].y == m[cont - 1].y) cont++;
        if (cont < n) {
            sum += distancia(m[cont - 1], m[cont]);
            max = m[cont].y;
        }
        for (int i = cont; i < n; i++) {
            if (m[i].y > max) {
                reta r = ret(m[i], m[i - 1]);
                float x = pontox(r, max);
                cord nova;
                nova.x = x;
                nova.y = max;
                sum += distancia(m[i], nova);
                max = m[i].y;
            }
        }
        cout << fixed << setprecision(2) << sum << endl;
    }
    return 0;
}
