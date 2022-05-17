#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m - 1; i++)
		if (n % i == 0 && n % (m - i) == 0) {
			cout << i << endl;
			return 0;
		}
	cout << -1 << endl;
}