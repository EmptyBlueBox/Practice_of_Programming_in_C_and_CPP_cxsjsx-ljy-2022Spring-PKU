#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string a;
	cin >> a;
	vector<char> v;
	for (auto i : a)
		v.push_back(i);
	do {
		for (auto i : v)
			cout << i;
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));
}