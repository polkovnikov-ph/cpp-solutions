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
	vector<vector<int>> profile(N, vector<int>(4));
	string const acgt = "ACGT";
	for (auto & p : m)
		for (int i = 0; i < N; ++i)
			++profile[i][acgt.find(p.first[i])];
	for (int i = 0; i < N; ++i) {
		auto & p = profile[i];
		cout << acgt[max_element(begin(p), end(p)) - begin(p)];
	}
	cout << endl;
	for (int i = 0; i < 4; ++i) {
		cout << acgt[i] << ':';
		for (auto & x : profile)
			cout << ' ' << x[i];
		cout << endl;
	}
}