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
	vector<string> lines;
	{
		string line;
		while (getline(cin, line))
			lines.push_back(line);
	}
	vector<pair<string, string>> m;
	for (size_t i = 0, ilen = lines.size(); i < ilen; ++i) {
		if (lines[i].size() == 0) break;
		if (lines[i][0] == '>') {
			string & name = lines[i++];
			string dna;
			for (; i < ilen; ++i) {
				if (lines[i].size() == 0 || lines[i][0] == '>') {
					--i;
					break;
				}
				dna += lines[i];
			}
			m.push_back(make_pair(dna, name.substr(1)));
		}
	}
	const int N = m.front().first.size();
	map<string, vector<string>> pref;
	vector<pair<string, string>> suff;
	for (auto & x : m) {
		pref[x.first.substr(0, 3)].push_back(x.second);
		suff.push_back(make_pair(x.first.substr(x.first.size() - 3), x.second));
	}
	for (auto & s : suff)
		for (auto & p : pref[s.first])
			if (s.second != p)
				cout << s.second << ' ' << p << endl;
}