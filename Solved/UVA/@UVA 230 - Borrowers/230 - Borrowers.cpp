// Author: Gilberto A. dos Santos
// Website: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=166

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct t {
	string title;
	string author;
	int on;
};

void change(string x, vector<t> &v, int tipo) {
	for(int i = 0; i < v.size(); i++) {
		if(v[i].title == x) {
			v[i].on = tipo;
			return;
		}
	}
}

bool comp(t x, t y) {
	if(x.author < y.author) return true;
	else if(x.author > y.author) return false;
	else return (x.title < y.title);
}

int main() {
	string temp;
    int debug;
	getline(cin,temp);
	vector<t> books;
	while(temp != "END") {
		t dado;
		int i = 1;
		while(true) {
			if(temp[i] == '"') break;
			dado.title += temp[i++];
		}
		i += 5;
		for( ; i < temp.size(); i++) dado.author += temp[i];
		dado.on = 2;
		books.push_back(dado);
		getline(cin,temp);
	}
	getline(cin,temp);
	sort(books.begin(),books.end(),comp);
	while(temp != "END") {
		string operacao = temp.substr(0,6);
		string temp_book;
        if(operacao != "SHELVE") temp_book = temp.substr(8,temp.size() - 9);
		if(operacao == "BORROW") change(temp_book,books,0);
		else if (operacao == "RETURN") change(temp_book,books,1);
		else {
			string before;
			bool entrou = false;
			for(int i = 0; i < books.size(); i++) {
				if(books[i].on == 0) continue;
				if(books[i].on == 2) {
					before = books[i].title;
					continue;
				}
                if(before.empty()) cout << "Put \"" << books[i].title << "\" first" << endl;
				else cout << "Put \"" << books[i].title << "\" after \"" << before << "\"" << endl;
                books[i].on = 2;
                before = books[i].title;
			}
			cout << "END" << endl;
		}
        getline(cin,temp);
	}
}

