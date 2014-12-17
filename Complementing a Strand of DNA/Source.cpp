#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	string s;
	getline(cin, s);
	const string src = "ACGT", dest = "TGCA";
	for (char & c : s) c = dest[src.find(c)];
	reverse(begin(s), end(s));
	cout << s;
}