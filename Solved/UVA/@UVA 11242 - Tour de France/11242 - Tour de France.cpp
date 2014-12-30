//Author:   Gilberto Alexandre dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2183

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int f, r;

int main() {
    while (scanf("%d", &f) && f != 0) {
        scanf("%d", &r);
        int rear[r];
        int front[f];
        vector<float> ratio;
        for (int i = 0; i < f; i++) scanf("%d", &front[i]);
        for (int i = 0; i < r; i++) scanf("%d", &rear[i]);
        for (int i = 0; i < f; i++)
            for (int j = 0; j < r; j++)
                ratio.push_back((float) rear[j] / front[i]);
        sort(ratio.begin(), ratio.end());
        float sum = 0;
        for (int i = 0; i < ratio.size() - 1; i++)
            sum = max(sum, (float) ratio[i + 1] / ratio[i]);
        cout << fixed << setprecision(2) << sum << endl;
    }
    return 0;
}