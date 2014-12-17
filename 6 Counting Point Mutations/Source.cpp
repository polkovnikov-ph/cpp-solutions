#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	string s, t;
	getline(cin, s);
	getline(cin, t);
	vector<bool> d(s.size());
	transform(begin(s), end(s), begin(t), begin(d), not_equal_to<int>());
	cout << count(begin(d), end(d), true) << endl;
}