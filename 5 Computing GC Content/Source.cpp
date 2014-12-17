#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> frac;

inline frac count_cont(string const & s) {
	return make_pair(count_if(begin(s), end(s), [](char const & c) {
		return c == 'C' || c == 'G';
	}), s.size());
}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	vector<string> lines;
	{
		string line;
		while (getline(cin, line))
			lines.push_back(line);
	}
	typedef pair<frac, string> z;
	vector<z> m;
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
			m.push_back(make_pair(count_cont(dna), name.substr(1)));
		}
	}
	sort(begin(m), end(m), [](z const & a, z const & b) {
		return a.first.first * b.first.second < b.first.first * a.first.second;
	});
	auto & x = m.back();
	cout << x.second << endl;
	cout << double(x.first.first) * 100 / x.first.second << endl;
}