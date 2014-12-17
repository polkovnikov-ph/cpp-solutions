#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, m;
	cin >> n >> m;
	long long a = 1, b = 1, c;
	for (int i = 3; i <= n; ++i)
		c = m * a + b, a = b, b = c;
	cout << b << endl;
}