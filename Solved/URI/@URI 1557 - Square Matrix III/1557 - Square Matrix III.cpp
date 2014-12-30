//Author:   Gilberto A. dos Santos
//Website:  http://www.urionlinejudge.com.br/judge/en/problems/view/1557

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;

int n;

int digit(int v) {
  ostringstream convert;
  string flag;
  convert << v;
  flag = convert.str();
  return flag.size();
}

inline void pr(int d) { for(int i = 0; i < d; i++) cout << " "; }

int main() {
  std::ios_base::sync_with_stdio(false);
  while(cin >> n && n) {

    int m[n][n];
    for(int j = 0, a = 1; j < n; j++) 
      m[0][j] = j ? m[0][j-1] * 2 : 1;
    for(int i = 1; i < n; i++) for(int j = 0; j < n; j++)
      m[i][j] = m[i-1][j] * 2;
    
    int max_digit = digit(m[n-1][n-1]);

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        int actual_digit = digit(m[i][j]);
        int next_digit = digit(m[i][j+1]);
        int left_digit = max_digit - actual_digit;
        pr(left_digit + (j > 0));
        cout << m[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
}
