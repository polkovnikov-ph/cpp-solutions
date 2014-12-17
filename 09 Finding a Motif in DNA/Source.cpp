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
	string s, t;
	getline(cin, s);
	getline(cin, t);
	int p = 0;
	for (;;) {
		int pos = s.find(t, p);
		if (pos == string::npos) break;
		cout << pos + 1 << ' ';
		p = pos + 1;
	}
	cout << endl;
}