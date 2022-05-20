#include <iostream>
using namespace std;

void solve(char a, char b, char c, int n) {//a到b
	if (n == 1) {
		cout << a << "->" << 1 << "->" << b << endl;
		return;
	}
	solve(a, c, b, n - 1);
	cout << a << "->" << n << "->" << b << endl;
	solve(c, b, a, n - 1);
}
int main() {
	int n;
	char a, b, c;
	cin >> n >> a >> b >> c;
	solve(a, b, c, n);
}