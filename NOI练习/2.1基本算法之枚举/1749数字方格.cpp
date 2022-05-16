#include <iostream>
using namespace std;

int main() {
	int n, tmpmax = -1;
	cin >> n;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n; k++)
				if ((i + j) % 2 == 0 && (j + k) % 3 == 0 && (i + j + k) % 5 == 0)
					tmpmax = max(i + j + k, tmpmax);
	cout << tmpmax << endl;
}