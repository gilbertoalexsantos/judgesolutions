//Author: Gilberto A. dos Santos
//Website:  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=969

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef pair<string, int> si;

inline string formated(string a) { return a.substr(0,4) + "-" + a.substr(5,2) + "-" + a.substr(6,2); }

int qt_year(string a, string b) {
  int y1, m1, d1;
  int y2, m2, d2;
  stringstream ss;
  ss << a.substr(0,4); ss >> y1; ss << a.substr(4,2); ss >> m1;
  ss << a.substr(6,2); ss >> d1; ss << b.substr(0,4); ss >> y2;
  ss << b.substr(4,2); ss >> m2; ss << b.substr(6,2); ss >> d2;
  return ((y2*365+m2*30+d2) - (y1*365+m1*30+d1)) / 365;
}

string sumYear(string a, int qt) {
  int y, m, d;
  stringstream ss;
  ss << a.substr(0,4); ss >> y; ss << a.substr(4,2); ss >> m;
  ss << a.substr(6,2); ss >> d;
  qt = qt * 365;
  int qt_up_year = qt / 365;
  qt %= 365;
  int qt_up_month = qt / 30;
  qt %= 30;
  int qt_up_day = qt;
}

int main() {
  int qt; scanf("%d\n",&qt);
  while(qt--) {
    string d;
    getline(cin, d);
    vector<si> lines;
    while(true) {
      string w; getline(cin, w);
      if(w.empty())
        break;
      string dat = w.substr(0,9);
      string number = w.substr(9,w.size() - 9);
      stringstream ss; ss << number;
      int n; ss >> n;
      lines.push_back(si(dat,n));
    }
    cout << formated(lines[0].first) << " No merit or demerit points." << endl;
    for(int i = 1; i < lines.size(); i++) {
      string w = lines[i].first;
      int nb = lines[i].second;
    }
  }
}
