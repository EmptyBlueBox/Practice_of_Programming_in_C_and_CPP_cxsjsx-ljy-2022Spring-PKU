#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int a = 2; a <= n; a++)
		for (int b = 2; b <= n; b++)//b可以小于a
			for (int c = b; c <= n; c++)//如果c小于b，可能会有bcd的重复
				for (int d = c; d <= n; d++)
					if (a * a * a == b * b * b + c * c * c + d * d * d)
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
}