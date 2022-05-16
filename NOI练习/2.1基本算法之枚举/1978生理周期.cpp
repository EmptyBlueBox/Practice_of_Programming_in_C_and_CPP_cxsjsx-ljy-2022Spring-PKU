#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, i;
	cin >> a >> b >> c >> d;
	for (i = d + 1; i < d + 21254; i++)//不要把上界卡到d+21252太死
		if ((i - a) % 23 == 0)
			for (; i < d + 21254; i += 23)
				if ((i - b) % 28 == 0)
					for (; i < d + 21254; i += 23 * 28)
						if ((i - c) % 33 == 0) {
							cout << i - d << endl;
							return 0;
						}
}