//Author: Gilberto A. dos Santso
//Website: http://codeforces.com/contest/501/problem/B

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int MAX = 5000;

map<string, int> nameToVert;
map<int, string> vertToName;
vector<int> adj[MAX];
int degree_in[MAX], degree_out[MAX];
int n;
int cntVert = 0;

int ins(string &a) {
  map<string, int>::iterator it = nameToVert.find(a);
  if (it == nameToVert.end()) {
    nameToVert[a] = cntVert;
    vertToName[cntVert] = a;
    return cntVert++;
  } else {
    return it->second;
  }
}

int dfs(int u, int parent=-1) {
  for (int i = 0; i <  adj[u].size(); i++) {
    int v =  adj[u][i];
    if (parent != v)
      return dfs(v, u);
  }
  return u;
}

int main() {
  memset(degree_in, 0, sizeof degree_in);
  memset(degree_out, 0, sizeof degree_out);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a1, a2;
    cin >> a1 >> a2;
    int v1 = ins(a1), v2 = ins(a2);
     adj[v1].push_back(v2);
    degree_in[v2]++;
    degree_out[v1]++;
  }

  vector<int> verts;
  for (int i = 0; i < cntVert; i++) {
    if (degree_in[i] == 0 && degree_out[i] == 1) {
      verts.push_back(i);
    }
  }

  cout << verts.size() << endl;
  for (int i = 0; i < verts.size(); i++) {
    cout << vertToName[verts[i]] << " ";
    int last = dfs(verts[i]);
    cout << vertToName[last] << endl;
  }
}
