#include <iostream>
#include <algorithm>
using namespace std;

bool isrev(string a) {
	string b = a;
	reverse(b.begin(), b.end());
	return a == b;
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		string a;
		cin >> a;
		int max_len = 1, l = 0, r = 0;
		for (int i = 0; i < a.length(); i++)
			for (int j = i; j < a.length(); j++)
				if (isrev(a.substr(i, j - i + 1)) && j - i + 1 > max_len)
					l = i, r = j, max_len = j - i + 1;
		for (int i = l; i <= r; i++)
			cout << a[i];
		cout << endl;
	}
}