#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	string s;
	getline(cin, s);
	const string patt = "ACGT";
	int counts[4] = {};
	for (char c : s) ++counts[patt.find(c)];
	for (int c : counts) cout << c << ' ';
}