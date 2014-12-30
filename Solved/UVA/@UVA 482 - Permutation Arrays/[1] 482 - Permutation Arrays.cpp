//Author: Gilberto A. dos Santos
//Website:http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=423

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,string> ii;

vector<ii> arr;
string word;

void clear() {
  arr.clear();
}

int main() {
  int T;
  scanf("%d\n\n",&T);
  while(T--) {
    clear();
    getline(cin,word);
    stringstream ss(word);
    int num;
    while(ss >> num)
      arr.push_back(ii(num,"abc"));
    for(int i = 0; i < arr.size(); i++)
      cin >> arr[i].second;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < arr.size(); i++)
      cout << arr[i].second << endl;
    if(T)
      puts("");
    getchar(); getchar();
  }
}
