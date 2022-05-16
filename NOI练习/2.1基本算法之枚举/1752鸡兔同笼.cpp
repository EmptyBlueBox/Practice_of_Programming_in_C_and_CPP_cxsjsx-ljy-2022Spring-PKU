#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2) {
		cout << "0 0\n";
		return 0;
	}
	if (!(n % 4))
		cout << n / 4;
	else
		cout << n / 4 + 1;
	cout << ' ' << n / 2 << endl;
}