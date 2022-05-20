#include <iostream>
#include <cmath>
using namespace std;
void f(int n) {
	for (int i = 15; i >= 0; i--) {
		if (pow(2, i) <= n) {
			if (i == 0)
				cout << "2(0)";
			else if (i == 1)
				cout << "2";
			else {
				cout << "2(";
				f(i);
				cout << ")";
			}
			if (pow(2, i) != n)
				cout << "+";
			n -= pow(2, i);
		}
	}
}
int main() {
	int n;
	cin >> n;
	f(n);
}