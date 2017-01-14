//Author:   Gilberto A. dos Santos
//Website:  http://www.spoj.com/problems/VBOSS/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

struct Person {
  int i, s, h, c, b;
  Person(int i, int s, int h) : i(i), s(s), h(h), c(0), b(0) {}
  Person() : i(0), s(0), h(0), c(0), b(0) {}
  bool operator<(Person p) const {
    return s < p.s;
  }
};

bool cp(const Person &a, const Person &b) {
  if (a.h == b.h)
    return a.s < b.s;
  return a.h < b.h;
}

vector<Person> persons;
int n, q;

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    persons.clear();
    set<Person> s;
    map<int, Person> toPerson;
    
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
      Person p; scanf("%d %d %d", &p.i, &p.s, &p.h);
      persons.push_back(p);
      s.insert(p);
      toPerson[p.i] = p;
    }

    sort(persons.begin(), persons.end(), cp);

    for (int i = 0; i < n; i++) {
      Person now = persons[i];
      set<Person>::iterator f = s.find(now);
      if (f != s.end())
        s.erase(f);

      set<Person>::iterator it = s.lower_bound(now);
      if (it != s.end()) {
        Person p = *it;

        toPerson[p.i].c += toPerson[now.i].c + 1;
        toPerson[now.i].b = p.i;
      }
    }

    for (int i = 0; i < q; i++) {
      int id; scanf("%d", &id);
      printf("%d %d\n", toPerson[id].b, toPerson[id].c);
    }
  }
}
