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
	int m[3];
	double t = 0.0;
	for (int i = 2; i >= 0; --i) {
		cin >> m[i];
		t += m[i];
	}
	double s = 0.0;
	for (int i = 0; i < 3; ++i) if (m[i]) {
		for (int j = 0; j < 3; ++j) if (m[j]) {
			double p = (m[i] / t) * ((m[j] - (i == j)) / (t - 1));
			if (i == 2 || j == 2) {
				s += p;
			} else if (i == 1 && j == 1) {
				s += p * 3 / 4;
			} else if (i == 1 || j == 1) {
				s += p / 2;
			}
		}
	}
	cout << s << endl;
}