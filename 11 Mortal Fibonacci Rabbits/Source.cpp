#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <map>
#include <numeric>
using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, m;
	cin >> n >> m;
	typedef long long ll;
	vector<ll> z(m);
	z[0] = 1LL;
	for (int i = 1; i < n; ++i) {
		ll s = accumulate(begin(z) + 1, end(z), 0LL, plus<ll>());
		copy_backward(begin(z), end(z) - 1, end(z));
		z[0] = s;
	}
	cout << accumulate(begin(z), end(z), 0LL, plus<ll>()) << endl;
}