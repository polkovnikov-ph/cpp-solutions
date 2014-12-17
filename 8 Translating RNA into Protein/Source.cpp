#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	ifstream cod("codons.txt");
	map<string, string> codons;
	for (int i = 0; i < 64; ++i) {
		string s; 
		getline(cod, s);
		codons[s.substr(0, 3)] = s.substr(4);
	}
	string s;
	getline(cin, s);
	for (size_t i = 0, ilen = s.size(); i < ilen; i += 3) {
		string c = codons[s.substr(i, 3)];
		if (c == "Z") break;
		cout << c;
	}
	cout << endl;
}