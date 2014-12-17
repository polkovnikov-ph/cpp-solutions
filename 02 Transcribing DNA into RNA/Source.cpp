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
	replace(begin(s), end(s), 'T', 'U');
	cout << s;
}